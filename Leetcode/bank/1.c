#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j,*p;
    *returnSize=2;
    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                p=malloc(2*sizeof(int*));
                p[0]=i;
                p[1]=j;
                return p;
            }
        }
    }
    return NULL; 
}

int main(){
    int *a,nums[4]={2,7,11,15},k;
    a=twoSum(nums,4,9,&k);
    printf("%d%d",a[0],a[1]);
    free(a);
}