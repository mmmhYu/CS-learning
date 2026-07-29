#include<stdio.h>

void write_matrix(int **p,int n,int m){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",*(p+i)+j);
        }
    }
}