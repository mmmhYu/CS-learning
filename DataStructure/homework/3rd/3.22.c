#include"../SqStack_ppt.h"

int KVtable[128];
int relation[7][7];

int Is_OP(char c){}

int Calculate(int x,int y,char OP){
    switch (KVtable[OP])
    {
    case 0:
        return x + y;
    case 1:
        return x - y;
    case 2:
        return x * y;
    case 3:
        return x / y;
    default:
        return ERROR;
    }
}

//处理形如AB+CD*E/-的字符串后缀表达式，ABC等视作操作数
int CalPostfix(char *str){
    char c;
    SqStack OPND;
    InitStack(&OPND);
    
    while(*str){
        c = *str++;

        if(Is_OP(c)){
            int x,y;
            Pop(&OPND,&y);
            Pop(&OPND,&x);
            Push(&OPND,Calculate(x,y,c));
        }
        else
            Push(&OPND,c);
    }

    return GetTop(OPND);
}