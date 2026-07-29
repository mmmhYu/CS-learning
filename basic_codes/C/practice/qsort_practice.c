#include<stdio.h>
#include<stdlib.h>

int my_cmp(const void *a,const void *b){
    return (*(int*)a/10)%10-(*(int*)b/10)%10;
}

int main(){
    int arr[5] = {112,24,16324,72,137};
    qsort(arr,5,4,&my_cmp);
    for(int i = 0; i < 5; i++)
        printf("%d ",arr[i]);
}