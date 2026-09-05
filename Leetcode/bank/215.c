#include<stdio.h>
#include<stdlib.h>

int sup_sort(int *nums,int l,int r,int k){
    
    if(l >= r)
        return nums[k];

    int i = l, j = r,pivot = nums[l],tmp;
    while(i < j){
        while(i < j && nums[j] > pivot)
            j--;
        while(i < j && nums[i] < pivot)
            i++;
        
        if(i < j){
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    nums[j] = pivot;
    if (k <= j)return sup_sort(nums, l, j, k);
    else return sup_sort(nums, j + 1, r, k);
}

int findKthLargest(int* nums, int numsSize, int k) {

    return sup_sort(nums,0,numsSize-1,numsSize-k);

}



int main()
{
    int nums[] = {2,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    int ans = findKthLargest(nums, numsSize, k);

    printf("The %dth largest element is: %d\n", k, ans);

    return 0;
}