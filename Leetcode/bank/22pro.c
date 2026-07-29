#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void gen(char **rl,char *str,int l,int r,int n,int *count){
    if(l+r == 2*n){
        rl[(*count)] = (char*)malloc((2*n+1)*sizeof(char));
        strcpy(rl[(*count)++], str);
        return;
    }
    if(l<n){
        str[l+r] = '(';
        gen(rl,str,l+1,r,n,count);
    }
    if(l>r && l+r<2*n){
        str[l+r] = ')';
        gen(rl,str,l,r+1,n,count);
    }
}

 char** generateParenthesis(int n, int* returnSize) {
    char str[2*n+1],**rl;
    str[2*n] = 0;
    int l=0,r=0;
    rl = (char**)malloc(3000*sizeof(char*));
    gen(rl,str,l,r,n,returnSize);
    return rl;
}

int main() {
    int n = 7;         // 你可以改 1/2/3/4 测试
    int returnSize=0;

    // 生成结果
    char** result = generateParenthesis(n, &returnSize);

    // 打印所有括号组合
    printf("n = %d 时，共有 %d 个有效括号：\n", n, returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    // 释放内存（非常重要）
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}