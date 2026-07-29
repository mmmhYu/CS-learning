#include<math.h>
#include<stdio.h>
int myAtoi(char* s) {
    int is_minus = 1,res = 0;
    while(*s == ' ' && *s != 0)
        s++;
    if(*s != 0 && *s == '-'){
        is_minus = -1;
        s++;
    }
    else if (*s != 0 && *s == '+')
        s++;
    while(*s == '0' && *s != 0)
        s++;
    while(*s != 0 && *s >= 48 && *s <= 57){
        if(is_minus == 1 && (res > pow(2,31)/10 || res == (int)pow(2,31)/10 && *s-48>7))
            return pow(2,31)-1;
        else if (is_minus == -1 && (res < -pow(2,31)/10 || res == (int)-pow(2,31)/10 && *s-48>8))
            return -pow(2,31);
        res*=10;
        res+=is_minus*(*s-48);
        s++;
    }
    return res;
}


int main(){
    printf("%d",myAtoi("2147483648"));
}