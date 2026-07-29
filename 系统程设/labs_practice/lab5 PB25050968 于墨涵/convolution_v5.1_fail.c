#include <stdlib.h>
#include <string.h>

#include "convolution.h"

#define KERNEL_RADIUS (KERNEL_SIZE / 2)

/** 
 * 计算卷积核覆盖区域的加权和，包含边界检查。
 * 作为基线实现的一部分，保证正确性但性能较差。
 */
void calculateKernelResponse(int i, int j, int n, float *src, float *kernel, float *dst) {
    dst[i * n + j] = 0.0f;
    // 卷积核中心对称，ki, kj 从 0 到 KERNEL_SIZE-1
    int ki, kj;
    float pixel_value;
    for (kj = 0; kj < KERNEL_SIZE; ++kj) { //! 列优先访问，性能较差
        for (ki = 0; ki < KERNEL_SIZE; ++ki) {
            // 映射到 src 的偏移位置
            int i = i + ki - KERNEL_SIZE / 2;
            int j = j + kj - KERNEL_SIZE / 2;
            // 边界检查：如果 i,j 超出 src 范围，则视为 0
            if (i >= 0 && i < n && j >= 0 && j < n) {//! 引入大量分支，影响性能
                pixel_value = src[i * n + j];
            }
            else {
                pixel_value = 0.0f; 
            }
            dst[i * n + j] += pixel_value * kernel[ki * KERNEL_SIZE + kj];//! 读写内存开销较大
        }
    }
}

/**
 * 基线实现：直接在内层循环中进行边界检查，保证正确性但性能较差。
 * 作为性能优化的对照，并且提供了一个清晰的正确性基准。
 */
void baseline_convolution(int n, float *src, float *kernel, float *dst)
{
    int i, j;
    for (j = 0; j < n; ++j) {//! 列优先访问，性能较差
        for (i = 0; i < n; ++i) {
            // 对每个输出像素 (i,j)，计算卷积核覆盖区域的加权和
            calculateKernelResponse(i, j, n, src, kernel, dst);//! 调用函数（增加函数调用开销）
        }
    }
}


/**
 * 优化实现：请在此处实现你的卷积函数。
 */
void my_calculateKernelResponse(int i, int j, int n, float *src, float *kernel, float *dst) {
    dst[i * n + j] = 0.0f;
    // 卷积核中心对称，ki, kj 从 0 到 KERNEL_SIZE-1
    int k0 = kernel[0],k1 = kernel[1], k2 = kernel[2], k3 = kernel[3], k4 = kernel[4];
    int i0 = i, i1 = i+1, i2 = i+2, i3 = i+3, i4 = i+4,
        j0 = j, j1 = j+1, j2 = j+2, j3 = j+3, j4 = j+4;
        dst[i * n + j] += k0*(src[i0*(n+4)+j0]+src[(i1)*(n+4)+j0]+src[(i2)*(n+4)+j0]+src[(i3)*(n+4)+j0]+src[(i4)*(n+4)+j0]);
        dst[i * n + j] += k1*(src[i0*(n+4)+j1]+src[(i1)*(n+4)+j1]+src[(i2)*(n+4)+j1]+src[(i3)*(n+4)+j1]+src[(i4)*(n+4)+j1]);
        dst[i * n + j] += k2*(src[i0*(n+4)+j2]+src[(i1)*(n+4)+j2]+src[(i2)*(n+4)+j2]+src[(i3)*(n+4)+j2]+src[(i4)*(n+4)+j2]);
        dst[i * n + j] += k3*(src[i0*(n+4)+j3]+src[(i1)*(n+4)+j3]+src[(i2)*(n+4)+j3]+src[(i3)*(n+4)+j3]+src[(i4)*(n+4)+j3]);
        dst[i * n + j] += k4*(src[i0*(n+4)+j4]+src[(i1)*(n+4)+j4]+src[(i2)*(n+4)+j4]+src[(i3)*(n+4)+j4]+src[(i4)*(n+4)+j4]);
}



void convolution(int n, float *src, float *kernel, float *dst)
{    
    int i, j;
    int new_amount = (n+4)*(n+4);//5*5要套两层
    float *new_src = malloc(new_amount*sizeof(float));
    memset(new_src,0,new_amount*sizeof(float));
    for(int p = 2; p <= n+1; p++){
        for(int q = 2; q <= n+1; q++){
            new_src[p*(n+4)+q] = src[(p-2)*n+q-2];
        }
    }

    for (j = 0; j < n; ++j) {//! 列优先访问，性能较差
        for (i = 0; i < n; ++i) {
            // 对每个输出像素 (i,j)，计算卷积核覆盖区域的加权和
            my_calculateKernelResponse(i, j, n, new_src, kernel, dst);//! 调用函数（增加函数调用开销）
        }
    }

    free(new_src);
}

