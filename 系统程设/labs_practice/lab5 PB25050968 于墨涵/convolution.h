#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#define KERNEL_SIZE 5

void baseline_convolution(int n, float *src, float *kernel, float *dst);
void convolution(int n, float *src, float *kernel, float *dst);

#endif
