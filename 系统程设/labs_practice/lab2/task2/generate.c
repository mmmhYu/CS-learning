#include<stdio.h>
#include<stdlib.h>

int **gen(int n,int m){
    int **p;
    p = malloc(n*sizeof(int*));
    if(p == NULL){
        printf("failed\n");
        return NULL;
    }
    for(int i = 0;i < n;i++){
        *(p+i) = malloc(m*sizeof(int));
        if(*(p+i) == NULL){
            printf("failed\n");
            return NULL;
        }
    }
    return p;
}