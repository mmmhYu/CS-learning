#ifndef LAB5_CONVOLUTION_H
#define LAB5_CONVOLUTION_H

#define LAB5_KERNEL_SIZE 5
#define LAB5_KERNEL_RADIUS 2

/*
 * src, kernel and dst must point to non-overlapping storage.
 * src and dst each contain n * n floats; kernel contains 25 floats.
 */
void convolution(int n,
                 const float *restrict src,
                 const float *restrict kernel,
                 float *restrict dst);

#endif
