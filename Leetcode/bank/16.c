#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int threeSumClosest(int* nums, int numsSize, int target) {
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
    //双指针
    int left,right,sum,closest = 99999999;
    for(i=1;i<numsSize-1;i++){
        left = 0;
        right = numsSize-1;
        while(left<i && right>i){
            sum = nums[i]+nums[left]+nums[right];
            if(abs(sum-target)<abs(closest-target))
                closest = sum;
            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else
                return target;
        }
    }
    return closest;
}

