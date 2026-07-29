int removeDuplicates(int* nums, int numsSize) {
    // 1. 处理边界情况：空数组直接返回0
    if (numsSize == 0) {
        return 0;
    }

    // 2. 慢指针slow：记录去重后数组的最后位置（初始为0）
    int slow = 0;

    // 3. 快指针fast：遍历数组（从1开始，因为slow已经指向第一个元素）
    for (int fast = 1; fast < numsSize; fast++) {
        // 4. 找到和slow位置不同的元素（不重复）
        if (nums[fast] != nums[slow]) {
            slow++; // 慢指针后移，准备存储新的不重复元素
            nums[slow] = nums[fast]; // 把不重复元素移到slow位置
        }
        // 重复元素则跳过，fast继续后移
    }

    // 5. 新数组长度是slow+1（因为slow是索引，从0开始）
    return slow + 1;
}


//笨办法
/*#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int i=numsSize,j,count=0;
    for(i=0;i<numsSize;i++){
        for(j=0;j<i;j++)
            if(nums[j]==nums[i])
                break;
            if(i==j)
            nums[count++]=nums[i];
    }
    return count;
}*/
