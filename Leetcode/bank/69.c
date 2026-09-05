#include<stdio.h>

/*int mySqrt(int x) {
    double i = 0, j = x, k;
    if(x == 1)
        return 1;
    while((int)i != (int)j){
        k = (i+j)/2;
        if(k*k > x)
            j = k;
        else if(k*k < x)
            i = k;
        else
            return (int)k;
    }
    return (int)i;
}*/

int mySqrt(int x){
    long long i = 0, j = x, mid;
    while(i <= j){
        mid = (i+j)/2;
        if(mid*mid > x)
            j = mid - 1;
        else if(mid*mid < x)
            i = mid + 1;
        else
             return mid;
    }
    return j;
}

int main(){
    printf("%d\n",mySqrt(8));
}