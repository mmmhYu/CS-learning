#include<string.h>
#include<stdio.h>
char* longestPalindrome(char* s){
    int n = strlen(s),i,j,count,max_count=0,k=0;
    char *forward,*backward,*max=NULL;
    forward = s;
    for(i=0;i <= n-1;i++){
        backward = s+n;
        k = 0;
        count = 0;
        while(backward >= s+i){
            if(*backward == *forward && *backward!=0 && *forward!=0){
                backward--;
                forward++;
                count++;
            }
            else{
                k++;
                count = 0;
                forward = s+i;
                backward = s+n-k;
            }
        }
        if(count > max_count){
            max_count = count;
            max = s+i;
        }
    }
    *(max+max_count) = 0;
    return max;
}

//另法（单次遍历）：根据回文中心（其实想到了的 没进行下去～）