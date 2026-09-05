#include<stdio.h>
#include<stdlib.h>

/*int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = numsSize - 1, mid = (i+j)/2, *range = malloc(2*sizeof(int));
    *returnSize = 2;

    if(!numsSize){
        range[0] = range[1] = -1;
        return range;
    }

    //确定左边界
    if(nums[0] == target){
        range[0] = 0;
    }
    else{
        i = 1;
        j = numsSize-1;
        while(i <= j){
            mid = (i+j)/2;
            if(nums[mid] == target && nums[mid-1] < target){
                range[0] = mid;
                break;
            }
            else if(nums[mid] > target || nums[mid] == target && nums[mid-1] == target)
                j = mid-1;
            else
                i = mid+1;
        }
        if(nums[mid] != target){
            range[0] = range[1] = -1;
            return range;
        }
    }
    //确定右边界
    if(nums[numsSize-1] == target){
        range[1] = numsSize-1;
    }
    else{
        i = 0;
        j = numsSize-2;
        while(i <= j){
            mid = (i+j)/2;
            if(nums[mid] == target && nums[mid+1] > target){
                range[1] = mid;
                break;
            }
            else if(nums[mid] < target || nums[mid] == target && nums[mid+1] == target)
                i = mid+1;
            else
                j = mid-1;
        }
    }
    return range;
}*/

/*int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i, j, mid, *range = malloc(2*sizeof(int));
    *returnSize = 2;

    if(!numsSize){
        range[0] = range[1] = -1;
        return range;
    }

    //确定左边界
    i = 0;j = numsSize-1;
    while(i <= j){
        mid = (i+j)/2;
        if(nums[mid] >= target)
            j = mid - 1;
        else
            i = mid + 1;
    }
    if(i > numsSize-1 || nums[i] != target){
        range[0] = range[1] = -1;
        return range;
    }
    range[0] = i;


    //确定右边界
    i = 0;j = numsSize-1;
    while(i <= j){
        mid = (i+j)/2;
        if(nums[mid] <= target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    range[1] = j;
    return range;
}*/

//尝试真的维护正确区间
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int i, j, mid, *range = malloc(2*sizeof(int));
    *returnSize = 2;

    if(!numsSize){
        range[0] = range[1] = -1;
        return range;
    }

    //确定左边界
    i = 0;j = numsSize;
    while(i < j){
        mid = (i+j)/2;
        if(nums[mid] >= target)
            j = mid;
        else
            i = mid + 1;
    }
    if(i > numsSize-1 || nums[i] != target){
        range[0] = range[1] = -1;
        return range;
    }
    range[0] = i;


    //确定右边界
    i = 0;j = numsSize;
    while(i < j){
        mid = (i+j)/2;
        if(nums[mid] > target)
            j = mid;
        else
            i = mid + 1;
    }
    range[1] = i;
    return range;
}

int main()
{
    int nums[] = {1,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 2;

    int returnSize = 0;

    int *res = searchRange(nums, numsSize, target, &returnSize);

    printf("[");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d", res[i]);
        if(i != returnSize - 1)
            printf(", ");
    }
    printf("]\n");

    free(res);

    return 0;
}