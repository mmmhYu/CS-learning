#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char corchar(char r){
    if(r == ')')
        return '(';
    else if(r == ']')
        return '[';
    else
        return '{';    
}

bool isValid(char* s) {
    int top=-1,i=0;
    char c[100];
    while(s[i]!=0){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            c[++top] = s[i];
            printf("%s\n",c);
        }
        else{
            if(c[top] == corchar(s[i])){
                top--;
            }
            else{
                return false;
            }
        }
        i++;
    }
    if(top == -1)
        return true;
    else
        return false;
}

int main() {
    // ========== 只需要修改这里的字符串 ==========
    const char* test_str = "({)}";  // 你想测试的字符串写在这里
    // ===========================================

    int result = isValid(test_str);
    printf("测试字符串: %s\n", test_str);
    printf("是否有效: %s\n", result ? "是（true）" : "否（false）");
    return 0;
}