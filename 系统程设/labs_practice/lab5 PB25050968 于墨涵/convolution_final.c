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
//优化方向：不调用函数
/*void my_calculateKernelResponse(int i, int j, int n, float *src, float *kernel, float *dst) {
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
}*/


void convolution(int n, float *src, float *kernel, float *dst){    
    int i, j;
    //建立扩展后的图像 避免边界判断
    int new_amount = (n+4)*(n+4);
    float *new_src = malloc(new_amount*sizeof(float));
    memset(new_src,0,new_amount*sizeof(float));
    //利用分块优化 但是结果错误。。。
    /*for(int p_block = 2; p_block < n+2; p_block += BLOCK_SIZE){
        for(int q_block = 2; p_block < n+2; p_block += BLOCK_SIZE){
            for(int p = p_block; p < p_block+BLOCK_SIZE; p++){
                for(int q = q_block; q < q_block+BLOCK_SIZE; q++){
                    new_src[p*(n+4)+q] = src[(p-2)*n+q-2];
                }
            }
        }
    }*/

    for(int p = 2; p <= n+1; p++){
        for(int q = 2; q <= n+1; q++){
            new_src[p*(n+4)+q] = src[(p-2)*n+q-2];
        }
    }

    //进入循环计算卷积
    for (int i_blk = 0; i_blk < n; i_blk += BLOCK_SIZE) {//改为先访问行且利用分块技术
        for (int j_blk = 0; j_blk < n; j_blk += BLOCK_SIZE) {
            for (i = i_blk; i < i_blk + BLOCK_SIZE; i++) {
                for (j = j_blk; j < j_blk + BLOCK_SIZE; j++) {
                    int ki, kj;
                    float pixel_value,tmp_sum = 0;//先存入寄存器最后赋值
                    for (ki = 0; ki < KERNEL_SIZE; ++ki) { 
                        for (kj = 0; kj < KERNEL_SIZE; ++kj) {
                            int ii = i + ki - KERNEL_SIZE/2;//利用宏替换减少循环内计算
                            int jj = j + kj - KERNEL_SIZE/2;
                            pixel_value = new_src[(ii+2) * (n+4) + jj+2];
                            tmp_sum += pixel_value * kernel[ki * KERNEL_SIZE + kj];
                        }
                    }
                    dst[i * n + j] = tmp_sum;
                }
            }
        }
    }
    free(new_src);
}


