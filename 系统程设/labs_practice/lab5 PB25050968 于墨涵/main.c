#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "convolution.h"

#define DEFAULT_ROUNDS 10
#define DEFAULT_SEED 1
#define ABS_EPS 1e-4f
#define REL_EPS 1e-3f

static double now_seconds(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec * 1e-6;
}

static void fill_random_image(float *a, int n, unsigned int seed)
{
    size_t i;
    size_t total = (size_t)n * (size_t)n;

    srand(seed);
    for (i = 0; i < total; ++i) {
        a[i] = (float)rand() / (float)RAND_MAX;
    }
}

static void fill_fixed_kernel(float *k)
{
    /*
     * 5x5 Gaussian-like kernel.
     * Dividing by 273 keeps values in a stable numeric range.
     */
    static const float raw[KERNEL_SIZE * KERNEL_SIZE] = {
        1.f, 4.f, 7.f, 4.f, 1.f,
        4.f, 16.f, 26.f, 16.f, 4.f,
        7.f, 26.f, 41.f, 26.f, 7.f,
        4.f, 16.f, 26.f, 16.f, 4.f,
        1.f, 4.f, 7.f, 4.f, 1.f
    };
    const float norm = 273.0f;
    int i;

    for (i = 0; i < KERNEL_SIZE * KERNEL_SIZE; ++i) {
        k[i] = raw[i] / norm;
    }
}

static int check_correctness(int n, float *ref, float *out)
{
    size_t idx;
    size_t total = (size_t)n * (size_t)n;
    float max_abs = 0.0f;
    int mismatch = 0;

    for (idx = 0; idx < total; ++idx) {
        float a = ref[idx];
        float b = out[idx];
        float abs_err = fabsf(a - b);
        float rel_err = abs_err / (fabsf(a) + 1e-8f);

        if (abs_err > max_abs) {
            max_abs = abs_err;
        }

        if (abs_err > ABS_EPS && rel_err > REL_EPS) {
            if (mismatch < 5) {
                int r = (int)(idx / (size_t)n);
                int c = (int)(idx % (size_t)n);
                printf("Mismatch[%d]: (%d,%d) ref=%f out=%f abs=%e rel=%e\n",
                       mismatch + 1,
                       r,
                       c,
                       a,
                       b,
                       abs_err,
                       rel_err);
            }
            mismatch++;
        }
    }

    printf("Max absolute error: %.6e\n", (double)max_abs);
    if (mismatch > 0) {
        printf("Total mismatches: %d\n", mismatch);
        return 0;
    }
    return 1;
}

static double benchmark_ms(void (*fn)(int, float *, float *, float *),
                           int n,
                           float *src,
                           float *kernel,
                           float *dst,
                           int rounds)
{
    int r;
    double total = 0.0;

    fn(n, src, kernel, dst);

    for (r = 0; r < rounds; ++r) {
        double t0 = now_seconds();
        fn(n, src, kernel, dst);
        total += now_seconds() - t0;
    }

    return total * 1000.0 / (double)rounds;
}

static void run_test(int n, int rounds, unsigned int seed, double *out_base, double *out_opt)
{
    size_t total = (size_t)n * (size_t)n;
    float *src = (float *)malloc(total * sizeof(float));
    float *kernel = (float *)malloc((size_t)KERNEL_SIZE * (size_t)KERNEL_SIZE * sizeof(float));
    float *ref = (float *)malloc(total * sizeof(float));
    float *out = (float *)malloc(total * sizeof(float));

    if (src == NULL || kernel == NULL || ref == NULL || out == NULL) {
        fprintf(stderr, "Memory allocation failed for n=%d.\n", n);
        exit(1);
    }

    fill_random_image(src, n, seed);
    fill_fixed_kernel(kernel);

    /* Warmup: run once to bring data into cache and stabilize clock */
    baseline_convolution(n, src, kernel, out);
    convolution(n, src, kernel, out);

    /* Correctness check */
    baseline_convolution(n, src, kernel, ref);
    convolution(n, src, kernel, out);

    if (!check_correctness(n, ref, out)) {
        printf("Correctness check failed for n=%d\n", n);
        exit(2);
    }

    *out_base = benchmark_ms(baseline_convolution, n, src, kernel, ref, rounds);
    *out_opt = benchmark_ms(convolution, n, src, kernel, out, rounds);

    double tpe_base = (*out_base * 1e6) / ((double)n * n); // ns per pixel
    double tpe_opt = (*out_opt * 1e6) / ((double)n * n);  // ns per pixel

    printf("N=%4d | TPE_Base: %6.2f ns | TPE_Opt: %6.2f ns | Speedup: %5.2fx\n",
           n, tpe_base, tpe_opt, *out_base / *out_opt);

    free(src);
    free(kernel);
    free(ref);
    free(out);
}

int main(int argc, char **argv)
{
    int rounds = DEFAULT_ROUNDS;
    unsigned int seed = DEFAULT_SEED;
    int sizes[] = {512, 1024, 2048, 4096, 8192};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    double log_speedup_sum = 0.0;
    int i;

    if (argc > 1) {
        rounds = atoi(argv[1]);
    }
    if (argc > 2) {
        seed = (unsigned int)atoi(argv[2]);
    }

    printf("=== Performance Benchmark (Geometric Mean) ===\n");
    printf("Kernel size: %d x %d\n", KERNEL_SIZE, KERNEL_SIZE);
    printf("Rounds per size: %d\n\n", rounds);

    for (i = 0; i < num_sizes; ++i) {
        double t_base, t_opt;
        run_test(sizes[i], rounds, seed, &t_base, &t_opt);
        log_speedup_sum += log(t_base / t_opt);
    }

    double gmean_speedup = exp(log_speedup_sum / num_sizes);
    printf("\nOverall Speedup (Geometric Mean): %.3fx\n", gmean_speedup);

    return 0;
}
