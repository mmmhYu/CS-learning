#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    int i=0,j,k=0;
    char *p=s;
    while (*p!=0)
    {
        j=0;
        while(s<p && *s!=*p){
            s++;
            j++;
        }
        if(s<p){
            s-=j-1;
            if(k>i)
                i=k;
            k=1;
            p=s+1;
        }
        else{
            s-=j;
            k++;
            if(k>i)
                i=k;
            p++;
        }   
    }
    return i;
}