/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
char** generateParenthesis(int n, int* returnSize) {
    int t=0,l=n,r=n,row=0;
    char **r;
    r = (char**)malloc(50*sizeof(char*));
    *r = (char*)malloc(2*n*sizeof(char));
    for(){
        r[row][0] = '(';
        for(int i=1;i<2*n;i++){
            
        }
    }
}