#include<stdio.h>
#include<stdlib.h>

int imin(int,int);

int main(){
    printf("%d\n",imin(5,3));
    return 0;
}

int imin(int a,int b){
    return a>b ? b : a;
}