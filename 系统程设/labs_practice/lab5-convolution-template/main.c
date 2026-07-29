#define _POSIX_C_SOURCE 200809L

#include "convolution.h"

#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ABS_TOLERANCE 1.0e-5f
#define REL_TOLERANCE 1.0e-5f
#define GUARD_FLOATS 16
#define GUARD_VALUE (-1234567.0f)

typedef void (*convolution_fn)(int, const float *, const float *, float *);

static volatile float benchmark_sink = 0.0f;

static uint32_t next_random(uint32_t *state)
{
    uint32_t x = *state;
    if (x == 0) {
        x = UINT32_C(0x6d2b79f5);
    }
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;
    return x;
}

static float random_signed_float(uint32_t *state)
{
    const float unit = (float)(next_random(state) >> 8) * (1.0f / 16777216.0f);
    return 2.0f * unit - 1.0f;
}

static int element_count(int n, size_t *count)
{
    if (n <= 0) {
        return 0;
    }
    const size_t width = (size_t)n;
    if (width > SIZE_MAX / width) {
        return 0;
    }
    *count = width * width;
    return *count <= SIZE_MAX / sizeof(float);
}

static float *allocate_floats(size_t count)
{
    if (count > SIZE_MAX / sizeof(float)) {
        return NULL;
    }
    return (float *)malloc(count * sizeof(float));
}

static void reference_convolution(int n,
                                  const float *src,
                                  const float *kernel,
                                  float *dst)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float sum = 0.0f;
            for (int ki = 0; ki < LAB5_KERNEL_SIZE; ++ki) {
                const int row = i + ki - LAB5_KERNEL_RADIUS;
                if (row < 0 || row >= n) {
                    continue;
                }
                for (int kj = 0; kj < LAB5_KERNEL_SIZE; ++kj) {
                    const int col = j + kj - LAB5_KERNEL_RADIUS;
                    if (col >= 0 && col < n) {
                        sum += src[(size_t)row * (size_t)n + (size_t)col]
                               * kernel[(size_t)ki * LAB5_KERNEL_SIZE
                                        + (size_t)kj];
                    }
                }
            }
            dst[(size_t)i * (size_t)n + (size_t)j] = sum;
        }
    }
}

static void fill_case(int pattern,
                      size_t count,
                      float *src,
                      float *kernel,
                      uint32_t seed)
{
    uint32_t state = seed;
    for (size_t i = 0; i < count; ++i) {
        src[i] = random_signed_float(&state);
    }

    for (int k = 0; k < LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE; ++k) {
        kernel[k] = 0.0f;
    }

    if (pattern == 0) {
        kernel[LAB5_KERNEL_RADIUS * LAB5_KERNEL_SIZE
               + LAB5_KERNEL_RADIUS] = 1.0f;
    } else if (pattern == 1) {
        for (int k = 0; k < LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE; ++k) {
            kernel[k] = ((float)k - 7.0f) / 31.0f;
        }
    } else {
        for (int k = 0; k < LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE; ++k) {
            kernel[k] = 0.25f * random_signed_float(&state);
        }
    }
}

static int compare_outputs(size_t count,
                           const float *reference,
                           const float *actual,
                           float *max_absolute_error,
                           size_t *bad_index)
{
    float max_error = 0.0f;
    for (size_t i = 0; i < count; ++i) {
        if (!isfinite(actual[i])) {
            *bad_index = i;
            *max_absolute_error = INFINITY;
            return 0;
        }

        const float error = fabsf(reference[i] - actual[i]);
        const float limit = ABS_TOLERANCE
                            + REL_TOLERANCE * fabsf(reference[i]);
        if (error > max_error) {
            max_error = error;
        }
        if (error > limit) {
            *bad_index = i;
            *max_absolute_error = max_error;
            return 0;
        }
    }

    *max_absolute_error = max_error;
    *bad_index = SIZE_MAX;
    return 1;
}

static int guards_are_intact(const float *storage, size_t count)
{
    for (size_t i = 0; i < GUARD_FLOATS; ++i) {
        if (storage[i] != GUARD_VALUE
            || storage[GUARD_FLOATS + count + i] != GUARD_VALUE) {
            return 0;
        }
    }
    return 1;
}

static int run_correctness_case(int n, int pattern, uint32_t seed)
{
    size_t count = 0;
    if (!element_count(n, &count)) {
        fprintf(stderr, "Invalid correctness-test size: %d\n", n);
        return 0;
    }

    float *src = allocate_floats(count);
    float *src_copy = allocate_floats(count);
    float *kernel = allocate_floats(LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE);
    float *kernel_copy = allocate_floats(LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE);
    float *reference = allocate_floats(count);
    float *guarded = allocate_floats(count + 2 * GUARD_FLOATS);

    if (src == NULL || src_copy == NULL || kernel == NULL
        || kernel_copy == NULL || reference == NULL || guarded == NULL) {
        fprintf(stderr, "Allocation failed in correctness test (N=%d).\n", n);
        free(src);
        free(src_copy);
        free(kernel);
        free(kernel_copy);
        free(reference);
        free(guarded);
        return 0;
    }

    fill_case(pattern, count, src, kernel, seed);
    memcpy(src_copy, src, count * sizeof(float));
    memcpy(kernel_copy, kernel,
           LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE * sizeof(float));
    reference_convolution(n, src, kernel, reference);

    for (size_t i = 0; i < count + 2 * GUARD_FLOATS; ++i) {
        guarded[i] = GUARD_VALUE;
    }
    float *actual = guarded + GUARD_FLOATS;
    for (size_t i = 0; i < count; ++i) {
        actual[i] = NAN;
    }

    convolution(n, src, kernel, actual);

    float max_error = 0.0f;
    size_t bad_index = SIZE_MAX;
    int ok = compare_outputs(count, reference, actual,
                             &max_error, &bad_index);
    if (!ok) {
        const size_t row = bad_index / (size_t)n;
        const size_t col = bad_index % (size_t)n;
        fprintf(stderr,
                "FAIL N=%d pattern=%d at (%zu,%zu): expected=%g actual=%g\n",
                n, pattern, row, col,
                (double)reference[bad_index], (double)actual[bad_index]);
    } else if (!guards_are_intact(guarded, count)) {
        fprintf(stderr, "FAIL N=%d pattern=%d: dst guard was overwritten.\n",
                n, pattern);
        ok = 0;
    } else if (memcmp(src, src_copy, count * sizeof(float)) != 0) {
        fprintf(stderr, "FAIL N=%d pattern=%d: src was modified.\n",
                n, pattern);
        ok = 0;
    } else if (memcmp(kernel, kernel_copy,
                      LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE * sizeof(float)) != 0) {
        fprintf(stderr, "FAIL N=%d pattern=%d: kernel was modified.\n",
                n, pattern);
        ok = 0;
    }

    free(src);
    free(src_copy);
    free(kernel);
    free(kernel_copy);
    free(reference);
    free(guarded);
    return ok;
}

static int run_correctness_tests(void)
{
    static const int sizes[] = {1, 2, 3, 4, 5, 7, 16, 31, 64, 127};
    int cases = 0;

    puts("=== Correctness Tests ===");
    printf("Tolerance: abs <= %.1e + %.1e * abs(reference)\n",
           (double)ABS_TOLERANCE, (double)REL_TOLERANCE);

    for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); ++i) {
        for (int pattern = 0; pattern < 3; ++pattern) {
            const uint32_t seed = UINT32_C(0x9e3779b9)
                                  ^ (uint32_t)sizes[i]
                                  ^ ((uint32_t)pattern << 16);
            if (!run_correctness_case(sizes[i], pattern, seed)) {
                return 0;
            }
            ++cases;
        }
    }

    printf("PASS: %d public correctness cases.\n", cases);
    return 1;
}

static double now_seconds(void)
{
    struct timespec value;
    if (clock_gettime(CLOCK_MONOTONIC, &value) != 0) {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }
    return (double)value.tv_sec + (double)value.tv_nsec * 1.0e-9;
}

static double time_convolution(convolution_fn function,
                               int n,
                               const float *src,
                               const float *kernel,
                               float *dst,
                               size_t sample_index)
{
    const double begin = now_seconds();
    function(n, src, kernel, dst);
    const double end = now_seconds();
    benchmark_sink += dst[sample_index];
    return end - begin;
}

static int benchmark_size(int n,
                          int rounds,
                          uint32_t seed,
                          double *speedup_out)
{
    size_t count = 0;
    if (!element_count(n, &count)) {
        fprintf(stderr, "Invalid benchmark size: %d\n", n);
        return 0;
    }

    float *src = allocate_floats(count);
    float *kernel = allocate_floats(LAB5_KERNEL_SIZE * LAB5_KERNEL_SIZE);
    float *reference = allocate_floats(count);
    float *actual = allocate_floats(count);
    if (src == NULL || kernel == NULL || reference == NULL || actual == NULL) {
        fprintf(stderr,
                "Allocation failed for N=%d (driver needs about %.0f MiB).\n",
                n, 3.0 * (double)count * sizeof(float) / (1024.0 * 1024.0));
        free(src);
        free(kernel);
        free(reference);
        free(actual);
        return 0;
    }

    fill_case(2, count, src, kernel, seed ^ (uint32_t)n);
    memset(reference, 0, count * sizeof(float));
    memset(actual, 0, count * sizeof(float));

    double baseline_seconds = 0.0;
    double optimized_seconds = 0.0;
    for (int round = 0; round < rounds; ++round) {
        const size_t sample = ((size_t)round * 9973u) % count;
        if ((round & 1) == 0) {
            baseline_seconds += time_convolution(reference_convolution,
                                                 n, src, kernel, reference,
                                                 sample);
            optimized_seconds += time_convolution(convolution,
                                                  n, src, kernel, actual,
                                                  sample);
        } else {
            optimized_seconds += time_convolution(convolution,
                                                  n, src, kernel, actual,
                                                  sample);
            baseline_seconds += time_convolution(reference_convolution,
                                                 n, src, kernel, reference,
                                                 sample);
        }
    }

    float max_error = 0.0f;
    size_t bad_index = SIZE_MAX;
    if (!compare_outputs(count, reference, actual,
                         &max_error, &bad_index)) {
        fprintf(stderr,
                "FAIL benchmark N=%d at (%zu,%zu): expected=%g actual=%g\n",
                n, bad_index / (size_t)n, bad_index % (size_t)n,
                (double)reference[bad_index], (double)actual[bad_index]);
        free(src);
        free(kernel);
        free(reference);
        free(actual);
        return 0;
    }

    const double baseline_tpe = baseline_seconds * 1.0e9
                                / ((double)rounds * (double)count);
    const double optimized_tpe = optimized_seconds * 1.0e9
                                 / ((double)rounds * (double)count);
    const double speedup = baseline_tpe / optimized_tpe;
    printf("N=%5d | Base: %9.2f ns/px | Student: %9.2f ns/px"
           " | Speedup: %6.2fx | Max error: %.3e\n",
           n, baseline_tpe, optimized_tpe, speedup, (double)max_error);
    *speedup_out = speedup;

    free(src);
    free(kernel);
    free(reference);
    free(actual);
    return 1;
}

static int run_benchmarks(int rounds, uint32_t seed, int max_n)
{
    static const int sizes[] = {512, 1024, 2048, 4096, 8192};
    double log_speedup_sum = 0.0;
    int size_count = 0;

    puts("\n=== Performance Benchmark ===");
    printf("Rounds per size: %d | Seed: %u | Maximum N: %d\n\n",
           rounds, seed, max_n);

    for (size_t i = 0; i < sizeof(sizes) / sizeof(sizes[0]); ++i) {
        if (sizes[i] > max_n) {
            continue;
        }
        double speedup = 0.0;
        if (!benchmark_size(sizes[i], rounds, seed, &speedup)) {
            return 0;
        }
        log_speedup_sum += log(speedup);
        ++size_count;
    }

    if (size_count == 0) {
        fprintf(stderr, "max_n must be at least 512.\n");
        return 0;
    }

    printf("\nOverall speedup (geometric mean over %d sizes): %.3fx\n",
           size_count, exp(log_speedup_sum / (double)size_count));
    return 1;
}

static int parse_long(const char *text, long minimum, long maximum, long *value)
{
    char *end = NULL;
    errno = 0;
    const long parsed = strtol(text, &end, 10);
    if (errno != 0 || end == text || *end != '\0'
        || parsed < minimum || parsed > maximum) {
        return 0;
    }
    *value = parsed;
    return 1;
}

static void print_usage(const char *program)
{
    fprintf(stderr,
            "Usage:\n"
            "  %s --test\n"
            "  %s --perf [rounds] [seed] [max_n]\n"
            "  %s [rounds] [seed]             (compatibility form)\n",
            program, program, program);
}

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "--test") == 0)) {
        return run_correctness_tests() ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    int argument = 1;
    if (strcmp(argv[1], "--perf") == 0) {
        argument = 2;
    } else if (argv[1][0] == '-') {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    long rounds = 5;
    long seed = 1;
    long max_n = 8192;
    if (argument < argc && !parse_long(argv[argument++], 1, 1000, &rounds)) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    if (argument < argc
        && !parse_long(argv[argument++], 0, UINT32_MAX, &seed)) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    if (argument < argc && !parse_long(argv[argument++], 512, 8192, &max_n)) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    if (argument != argc) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (!run_correctness_tests()) {
        return EXIT_FAILURE;
    }
    return run_benchmarks((int)rounds, (uint32_t)seed, (int)max_n)
           ? EXIT_SUCCESS : EXIT_FAILURE;
}
