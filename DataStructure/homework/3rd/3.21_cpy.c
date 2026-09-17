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
    while(GetTop(OPTR) != '#' || c != '#'){
        c = *str;
        //是操作符
        if(Is_OP(c)){
            char top_op = GetTop(OPTR);
            int i = KVtable[top_op],j = KVtable[c];
            while(!StackEmpty(OPTR) && relation[i][j] != -1){
                if(relation[i][j] == 1){
                    char x;
                    Pop(&OPTR,&x);
                    printf("%c ",x);
                }
                else{
                    char x;
                    Pop(&OPTR,&x);
                    str++;
                    break;
                }
                top_op = GetTop(OPTR);
                i = KVtable[top_op];
            }
            if(c != ')'){
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

int main()
{
    char test1[] = "#A+B*C#";
    char test2[] = "#A*B+C/D#";
    char test3[] = "#(A+B)*C#";
    char test4[] = "#A*(B+C)-D/E#";
    char test5[] = "#A+B*(C-D)/E#";
    char test6[] = "#(A+B)*(C-D)#";
    char test7[] = "#A*(B+C*(D-E))-F#";
    char test8[] = "#((A+B)*C-D)/(E+F)#";

    printf("Test 1: %s\n", test1);
    printf("Postfix: ");
    Trans(test1);

    printf("Test 2: %s\n", test2);
    printf("Postfix: ");
    Trans(test2);

    printf("Test 3: %s\n", test3);
    printf("Postfix: ");
    Trans(test3);

    printf("Test 4: %s\n", test4);
    printf("Postfix: ");
    Trans(test4);

    printf("Test 5: %s\n", test5);
    printf("Postfix: ");
    Trans(test5);

    printf("Test 6: %s\n", test6);
    printf("Postfix: ");
    Trans(test6);

    printf("Test 7: %s\n", test7);
    printf("Postfix: ");
    Trans(test7);

    printf("Test 8: %s\n", test8);
    printf("Postfix: ");
    Trans(test8);

    return 0;
}




