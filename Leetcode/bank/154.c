#include<stdio.h>
#include<stdlib.h>

/*int findMin(int* nums, int numsSize) {
    int l = 0, r = numsSize-1, mid,tmp = nums[0];

    while(l<numsSize-1 && nums[l] == nums[0])
        l++;
    while(r>0 && nums[r] == nums[0])
        r--;

    while (l < r){
        mid = (l+r)/2;
        if(nums[mid] > nums[0])
            l = mid + 1;
        else if(nums[mid] < nums[0])
            r = mid;
    }

    return nums[l]<nums[0]?nums[l]:nums[0];
}*/

int findMin(int* nums, int numsSize) {
    int l = 0, r = numsSize-1, mid;

    while (l < r){
        mid = (l+r)/2;
        if(nums[mid] > nums[r])
            l = mid + 1;
        else if(nums[mid] < nums[r])
            r = mid;
        else
            r--;
    }

    return nums[l];
}

int main(){
    int arr[5] = {1,2,3,4,1};
    printf("%d\n",findMin(arr,5));
}