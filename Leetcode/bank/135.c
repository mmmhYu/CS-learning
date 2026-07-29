#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int my_cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}

int my_locate(int *arr,int size,int goal){
    int i;
    for(i = 0; i < size && arr[i] != goal; i++){}
    return i;
}

//这样不对 对于相邻相等的情况还是没有搞好 因为一堆相等 
//他们分发个数是和与这一堆相邻的分数有关的如{1,2,2}按照我的算法就是1+2+1 
//诶不对 就是这样算
int candy(int* ratings, int ratingsSize) {
    int rt_cpy[ratingsSize];
    for(int d = 0; d < ratingsSize; d++)
        rt_cpy [d] = *(ratings+d);
    qsort(rt_cpy,ratingsSize,sizeof(int),my_cmp);
    int num = ratingsSize;
    for(int i = 0; i < ratingsSize - 1; i++){
        int index = my_locate(ratings,ratingsSize,rt_cpy[i]);
        if((index == 0 && ratings[index] > ratings[index+1]) 
        || (index == ratingsSize-1 && ratings[index] > ratings[index-1]) 
        || (ratings[index] > ratings[index-1] || ratings[index] > ratings[index+1])){
            printf("%d\n",index);
            num++;
        }
            
    }
    return num;
}*/

//先尝试了一次遍历 右边是否比左边大 主要问题出在连续相等上 会全置0 如果比后面大就会有问题
//所以需要再一次遍历 看左边是否比右边大 但是注意从右往左 要处理递增
int candy(int* ratings, int ratingsSize){
    int i,j,*count,candy_amount = 0;
    count = (int*)malloc(ratingsSize * sizeof(int));

    for(int i = 0; i < ratingsSize; i++){
        count[i] = 1;
    }
    for(i = 1; i < ratingsSize; i++){
        if(ratings[i] > ratings[i-1])
            count[i] = count[i-1] + 1;
    }
    for(j = ratingsSize-1; j > 0; j--){
        if(ratings[j-1] > ratings[j]){
            if(count[j-1]>count[j])
                continue;
            else
                count[j-1] = count[j] + 1;
        }
    }
    for(i = 0; i < ratingsSize; i++)
        candy_amount += count[i];
    return candy_amount;
}

int main(){
    int ratings[7] = {1,2,87,87,87,2,1};
    printf("%d\n",candy(ratings,7));
}