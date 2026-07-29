#include<stdio.h>
#include<stdlib.h>
/*int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result,n = 0;
    result = (int**)malloc(100*sizeof(int*));
    *returnSize = 0;
    for(int i=0;i<10;i++){
        result[i] = (int*)malloc(3*sizeof(int));
    }
    int i,j,k;
    for(i=0;i<numsSize-2;i++){
        for(j=i+1;j<numsSize-1;j++){
            for(k=j+1;k<numsSize;k++){
                if(nums[k] == -(nums[i]+nums[j])){
                    result[n][0] = nums[i];
                    result[n][1] = nums[j];
                    result[n][2] = nums[k];
                    n++;
                    break;
                }
            }
        }
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n*sizeof(int));
    for(i=0;i<*returnSize;i++)
        (*returnColumnSizes)[i]=3;
    return result;
}*/

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i,j,k,min,temp;
    //排序
    for(i=0;i<numsSize-1;i++){
        min = nums[i];
        for(j=i+1;j<numsSize;j++){
            if(nums[j]<min){
                min = nums[j];
                k = j;
            }
            if(min != nums[i]){
                temp = nums[i];
                nums[i] = min;
                nums[k] = temp;
            }   
        }
    }
    //双指针算法
    int **result,n = 0,left,right,sum_1,count=0;
    result = (int**)malloc(100*sizeof(int*));
    for(int i=0;i<10;i++){
        result[i] = (int*)malloc(3*sizeof(int));
    }
    *returnSize = 0;
    k = 0;
    for(i=1;i<numsSize-1;i++){
        if(k == 1&&nums[i]==nums[i-1]){
            continue;
        }
        left = i-1;
        right = i+1;
        k = 0;
        while(left>=0 && right<numsSize){
            sum_1 = nums[left] + nums[right];
            if(sum_1 > -nums[i]){
                left--;
            }
            else if(sum_1 < -nums[i]){
                right++;
            }
            else{
                k = 1;
                result[count][0] = nums[left];
                result[count][1] = nums[i];
                result[count][2] = nums[right];
                count++;
                left++;
                right++;
                while(left>=0 && nums[left] == nums[left+1]){
                    left--;
                }
                while(right<numsSize && nums[right] == nums[right-1]){
                    right++;
                }
            }
        }
    }
        *returnSize = count;
        *returnColumnSizes = (int*)malloc(count*sizeof(int));
        for(i=0;i<*returnSize;i++)
            (*returnColumnSizes)[i]=3;
    
    return result;
}

// 测试主函数
int main() {
    // 示例 1 输入
    int nums[] = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int returnSize;
    int* returnColumnSizes;
    
    // 调用你的函数
    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    
    // 打印结果
    printf("测试结果：\n");
    printf("找到 %d 个三元组：\n", returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");
    
    // 预期输出: [[-1,-1,2],[-1,0,1]]
    
    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}