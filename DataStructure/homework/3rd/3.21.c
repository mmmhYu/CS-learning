#include"../SqStack_ppt.h"

#define Elemtype char
int Is_OP(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#';
}

void Trans(char *str){
    int KVtable[128] = {0};
    KVtable['+'] = 0;
    KVtable['-'] = 1;
    KVtable['*'] = 2;
    KVtable['/'] = 3;
    KVtable['('] = 4;
    KVtable[')'] = 5;
    KVtable['#'] = 6;

    //用1表示'>',0表示'=',-1表示'<',2表示不会有这个情况
    //栈顶 > 新进入的运算符，则先算栈顶并出栈
    //不过我的算法，好像')'不会入栈
    int relation[7][7] = {
        {1,1,-1,-1,-1,1,1},
        {1,1,-1,-1,-1,1,1},
        {1,1,1,1,-1,1,1},
        {1,1,1,1,-1,1,1},
        {-1,-1,-1,-1,-1,0,2},
        {1,1,1,1,2,1,1},
        {-1,-1,-1,-1,-1,2,0}
    };

    SqStack OPTR;
    InitStack(&OPTR);

    Push(&OPTR,'#');
    str++;
    char c = *str;
    while(GetTop(OPTR) != '#' || *str != '#'){
        c = *str;
        //是操作符
        if(Is_OP(c)){
            char top_op = GetTop(OPTR);
            int i = KVtable[top_op],j = KVtable[c];
            if(relation[i][j] == 1){
                char x;
                Pop(&OPTR,&x);
                printf("%c ",x);
            }
            else if(relation[i][j] == 0){
                char x;
                Pop(&OPTR,&x);
                str++;
            }
            else{
                Push(&OPTR,c);
                str++;
            }
        }
        //是数字
        else{
            printf("%c ",c);
            str++;  
        }
    }

    printf("\n");
}

int main(void)
{
    char tests[][100] = {
        "#A-B-C#",       // 同优先级减法：左结合
        "#A/B*C#",       // 同优先级乘除：左结合
        "#A#",           // 只有一个操作数
        "#(((A)))#",     // 多层无意义括号
        "#A+B-C*D/E#"    // 混合优先级 + 同级运算
    };

    int n = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < n; i++) {
        printf("Test %d: %s\n", i + 1, tests[i]);
        printf("Postfix: ");
        Trans(tests[i]);
    }

    return 0;
}