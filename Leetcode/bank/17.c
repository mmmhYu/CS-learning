#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char** letterCombinations(char* digits, int* returnSize) {
    char **result,*a[]={0,0,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n=strlen(digits),nn,i,size[]={0,0,3,3,3,3,3,4,3,4},*int_digits;
    nn = 
    result = (char**)malloc(nn*sizeof(char*));
    int_digits = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        *(result+i) = (char*)malloc((n+1)*sizeof(char));//应该要保留一位给“\0”?
    }
    
}