#include<stdio.h>
#include<stdlib.h>

/*int removeElement(int* nums, int numsSize, int val){
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == val){
            count++;
            for(int j = i; j < numsSize-1; j++){
                nums[j] = nums[j+1];
            }
            numsSize--;
            i--;
        }
    }
    return numsSize;
}*/

//双指针
int removeElement(int* nums, int numsSize, int val){
    int fast,slow = 0;
    for(fast = 0; fast < numsSize; fast++){
        if(nums[fast] != val){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}


int main(){
    int nums[4] = {3,2,2,3};
    for(int i = 0; i < removeElement(nums,4,3); i++){
        printf("%d ",nums[i]);
    }
}