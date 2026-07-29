#include<stdio.h>
#include<stdlib.h>

void free_matrix(int **p,int n){
    for(int i = 0;i<n;i++){
        free(*(p+i));
    }
    free(p);
}