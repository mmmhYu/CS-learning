#include <stdlib.h>
#include <string.h>

#include "convolution.h"

#define KERNEL_RADIUS (KERNEL_SIZE / 2)
#define BLOCK_SIZE 32

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
            int ii = i + ki - KERNEL_SIZE / 2;
            int jj = j + kj - KERNEL_SIZE / 2;
            // 边界检查：如果 ii,jj 超出 src 范围，则视为 0
            if (ii >= 0 && ii < n && jj >= 0 && jj < n) {//! 引入大量分支，影响性能
                pixel_value = src[ii * n + jj];
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
/*void my_calculateKernelResponse(int i, int j, int n, float *src, float *kernel, float *dst) {
    dst[i * n + j] = 0.0f;
    int ki, kj;
    float pixel_value,tmp_sum = 0;
    for (ki = 0; ki < KERNEL_SIZE; ++ki) { 
        for (kj = 0; kj < KERNEL_SIZE; ++kj) {
            int ii = i + ki - KERNEL_SIZE / 2;
            int jj = j + kj - KERNEL_SIZE / 2;
            // 边界检查：如果 ii,jj 超出 src 范围，则视为 0
            if (ii >= 0 && ii < n && jj >= 0 && jj < n) {//! 引入大量分支，影响性能
                pixel_value = src[ii * n + jj];
            }
            else {
                pixel_value = 0.0f; 
            }
            tmp_sum += pixel_value * kernel[ki * KERNEL_SIZE + kj];//先存入寄存器最后一并写入
        }
    }
    dst[i * n + j] = tmp_sum;
}*/

//优化方向：循环展开
void convolution(int n, float *src, float *kernel, float *dst)
{    
    int i, j,rad = KERNEL_RADIUS;
    //边界初始化
    int new_amount = (n+4)*(n+4);//5*5要套两层
    float *new_src = malloc(new_amount*sizeof(float));
    //似乎memset还要更快？
    memset(new_src,0,new_amount*sizeof(float));
    for(int p = 2; p <= n+1; p++){
        for(int q = 2; q <= n+1; q++){
            new_src[p*(n+4)+q] = src[(p-2)*n+q-2];
        }
    }

    for (int i_blk = 0; i_blk < n; i_blk += BLOCK_SIZE) {
        for (int j_blk = 0; j_blk < n; j_blk += BLOCK_SIZE) {
            for (i = i_blk; i < i_blk + BLOCK_SIZE; i++) {
                for (j = j_blk; j < j_blk + BLOCK_SIZE; j++) {
                    dst[i * n + j] = 0.0f;
                    int ii = i-2, jj = j-2, k0 = kernel[0],k1 = kernel[1],k2 = kernel[2],k3 = kernel[3],k4 = kernel[4];
                    float pixel_value,tmp_sum = 0;
                    int ii1 = ii+1,ii2 = ii+2, ii3 = ii+3, ii4 = ii+4;
                    tmp_sum += k0*(new_src[ii*(n+4)+jj]+new_src[(ii1)*(n+4)+jj]+new_src[(ii2)*(n+4)+jj]+new_src[(ii3)*(n+4)+jj]+new_src[(ii4)*(n+4)+jj]);
                    jj++;
                    tmp_sum += k1*(new_src[ii*(n+4)+jj]+new_src[(ii1)*(n+4)+jj]+new_src[(ii2)*(n+4)+jj]+new_src[(ii3)*(n+4)+jj]+new_src[(ii4)*(n+4)+jj]);
                    jj++;
                    tmp_sum += k2*(new_src[ii*(n+4)+jj]+new_src[(ii1)*(n+4)+jj]+new_src[(ii2)*(n+4)+jj]+new_src[(ii3)*(n+4)+jj]+new_src[(ii4)*(n+4)+jj]);
                    jj++;
                    tmp_sum += k3*(new_src[ii*(n+4)+jj]+new_src[(ii1)*(n+4)+jj]+new_src[(ii2)*(n+4)+jj]+new_src[(ii3)*(n+4)+jj]+new_src[(ii4)*(n+4)+jj]);
                    jj++;
                    tmp_sum += k4*(new_src[ii*(n+4)+jj]+new_src[(ii1)*(n+4)+jj]+new_src[(ii2)*(n+4)+jj]+new_src[(ii3)*(n+4)+jj]+new_src[(ii4)*(n+4)+jj]);
                    dst[i * n + j] = tmp_sum;
                }
            }
        }
    }
}

