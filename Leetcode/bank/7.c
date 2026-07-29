#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int reverse(int x) {
    int is_minus,rev=0;
    if(x>0)
        is_minus = 0;
    else
        is_minus = 1;
    x=labs(x);
    while(x>0){
        if(rev > pow(2,31)/10 || (is_minus == 1 && rev == pow(2,31)/10 && (10*rev+x)>pow(2,31)) || (is_minus == 0 && rev == pow(2,31)/10 && (10*rev+x)>pow(2,31)-1))
            return 0;
        rev *= 10;
        rev += x%10;
        x/=10;
        printf("%d\n",rev);
        
    }
    rev=is_minus == 1?(-rev):rev;
    return rev;   
}



int main(){
    printf("%d",reverse(-2147483412));
    return 0;
}