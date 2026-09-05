#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool validPalindrome(char* s){
    char *l = s,*r = s,*ll,*rr;
    while(*r)
        r++;
    r--;
    while(l < r){
        if(*l == *r){
            l++;
            r--;
            continue;
        }
        else{
            ll = l; rr = r;
            l += 1;
            while(l < r){
                if(*l == *r){
                    l++;r--;
                }
                else
                    break;
            }
            if(l >= r)
                return 1;
            l = ll;r = rr-1;
            while(l < r){
                if(*l == *r){
                    l++;r--;
                }
                else
                    break;
            }
            if(l >= r)
                return 1;
            break;
        }
    }
    if(l >= r)
        return 1;
    return 0;
}

int main()
{
    char s5[] = "abc";

    printf("%s -> %s\n", s5, validPalindrome(s5) ? "true" : "false");

    return 0;
}