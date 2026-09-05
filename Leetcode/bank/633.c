#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool judgeSquareSum(int c) {
    long long int i = 0, j = sqrt(c);
    while(i <= j){
        if((i*i+j*j) > c)
            j--;
        else if((i*i+j*j) < c)
            i++;
        else
            return 1;
    }
    return 0;
}