#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int a[100] = {0},k = 0,step=1;
    for(int i = 0;i<numsSize;i++){
        if(nums[i] == val){
            a[k++] = i;
        }
    }
    for(int i = 1;i<=k;i++){
        if(i!=k){
            for(int j = a[i-1]+1;j<a[i];j++){
                nums[j-step] = nums[j];
            }
        }
        else{
            for(int j = a[k-1]+1;j<numsSize;j++){
                nums[j-step] = nums[j];
            }
        }
        step++;
    }
    return numsSize-k;
}

int main() {
    // 测试用例 1
    int nums1[] = {4,5};
    int val1 = 4;
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    
    printf("--- 测试用例 1 ---\n");
    printf("输入数组: [4,5], 移除值: %d\n", val1);
    int k1 = removeElement(nums1, size1, val1);
    printf("返回长度: %d\n", k1);
    printf("修改后的数组前 %d 个元素: [", k1);
    for(int i=0; i<k1; i++){
        printf("%d", nums1[i]);
        if(i != k1-1) printf(",");
    }
    printf("]\n\n");

    // 测试用例 2
    int nums2[] = {0, 1, 2, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    
    printf("--- 测试用例 2 ---\n");
    printf("输入数组: [0,1,2,2,2,3,0,4,2], 移除值: %d\n", val2);
    int k2 = removeElement(nums2, size2, val2);
    printf("返回长度: %d\n", k2);
    printf("修改后的数组前 %d 个元素: [", k2);
    for(int i=0; i<k2; i++){
        printf("%d", nums2[i]);
        if(i != k2-1) printf(",");
    }
    printf("]\n");

    return 0;
}