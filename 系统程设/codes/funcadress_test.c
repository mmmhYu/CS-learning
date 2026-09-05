#include<stdio.h>
#include<stdlib.h>

int add(int a,int b){
    return a+b;
}

int main(){
    printf("%p\n%p\n%p\n",add,*add,&add);
}