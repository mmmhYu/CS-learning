#include<stdio.h>

int sort(int **p,int k,int n,int m,int *cols){
    int count = 0,temp_sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp_sum += *(*(p+i)+j);
        }
        if(temp_sum >= k*m){
            cols[count++] = i;
        }
    }
    return count;
}