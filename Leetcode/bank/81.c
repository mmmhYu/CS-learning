#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int bisch(int l,int r,int numsSize, int *nums,int target){
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(nums[mid] > target)
            r = mid;
        else if(nums[mid] < target)
            l = mid+1;
        else
            return 1;
    }
    
    if(l >= numsSize || nums[l] != target)
        return 0;
    else
        return 1;

}

bool search(int* nums, int numsSize, int target) {
    int l = 0,r = numsSize,mid,turn = nums[0];

    if(target == nums[0])
        return 1;
    while(nums[l] == nums[0])
        l++;
    while(r >= 0 && nums[r] == nums[0])
        r--;
    r++;
    while(l < r){
        mid = (l+r)/2;
        if(nums[mid] < turn)
            r = mid;
        else
            l = mid+1;
    }
    printf("%d\n",l);
    //l的位置是首最小元

    if(target > nums[0])
        return bisch(0,l,numsSize,nums,target);
    else
        return bisch(l,numsSize,numsSize,nums,target);        
}

int main(){
    int arr[] = {1};
    printf("%d\n",search(arr,1,0));
}