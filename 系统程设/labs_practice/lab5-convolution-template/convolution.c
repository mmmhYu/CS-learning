#include "convolution.h"

#include <stddef.h>

/*
 * Correct starter implementation. Optimize this function while preserving
 * its interface and numerical result within the tolerance in the assignment.
 */
void convolution(int n,
                 const float *restrict src,
                 const float *restrict kernel,
                 float *restrict dst)
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
