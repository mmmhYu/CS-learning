#include<stdio.h>
#include<stdlib.h>

/*int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i,j;
    for(i = 0; i < numbersSize; i++){
        int res = target - numbers[i],l = i+1,r = numbersSize-1;
        while(l <= r){
            j = (l+r)/2;
            if(numbers[j] < res)
                l = j+1;
            else if (numbers[j] > res)
                r = j-1;
            else{
                int *result = malloc(2*sizeof(int));
                result[0] = i+1;
                result[1] = j+1;
                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}*/

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i=0,j=numbersSize-1;
    while(i<j){
        int sum = numbers[i] + numbers[j];
        if(sum < target){
            i++;
        }
        else if(sum > target){
            j--;
        }
        else{
            int *result = malloc(2*sizeof(int));
            result[0] = i+1;
            result[1] = j+1;
            *returnSize = 2;
            return result;
        }
    }
    return NULL;
}

int main()
{
    int numbers[] = {2,7,11,13};
    int target = 9;

    int returnSize = 0;

    int* ans = twoSum(numbers, 4, target, &returnSize);

    printf("result: ");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(ans);

    return 0;
}