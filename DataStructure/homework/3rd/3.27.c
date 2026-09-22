#include<stdio.h>

int akm(int m,int n){
    if(!m)
        return n + 1;
    
    if(!n)
        return akm(m-1,1);

    return akm(m-1,akm(m,n-1));
}

int main(void)
{
    printf("1\n");
    printf("akm(4,2) = %d\n", akm(4,2));

    return 0;
}