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
    printf("akm(0, 0) = %d\n", akm(1, 2));
    printf("akm(0, 5) = %d\n", akm(0, 5));
    printf("akm(1, 0) = %d\n", akm(1, 0));
    printf("akm(1, 5) = %d\n", akm(1, 5));
    printf("akm(2, 0) = %d\n", akm(2, 0));
    printf("akm(2, 3) = %d\n", akm(2, 3));
    printf("akm(3, 2) = %d\n", akm(3, 2));

    return 0;
}