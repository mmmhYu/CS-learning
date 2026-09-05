#include<stdio.h>
#include<stdlib.h>

typedef int(*MathFunc)(int,int);

int my_add(int a,int b){
    return a+b;
}

int my_sub(int a,int b){
    return a-b;
}

int my_mul(int a,int b){
    return a*b;
}

int my_div(int a,int b){
    return a/b;
}

void my_print(int x,int y,int(*op)(int,int)){
    printf("%d\n",op(x,y));
}

int main(){
    int a=2,b=4,sum=0;
    MathFunc pf;
    pf = my_mul;
  //printf("%d\n",pf(a,b));
    my_print(a,b,pf);
    return 0;
    MathFunc ops[4] = {my_add,my_sub,my_mul,my_div};
  //int (*ops)(int,int)[4]=...  
}