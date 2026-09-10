#include<stdio.h>

typedef struct SqList{
    int *elem;
    int size;
    int len;
    int inc;
}*SqList;

#define less -1
#define equal 0
#define more 1
#define Status int

Status cmp_SqList(SqList A, SqList B){
    int A_len = A->len,B_len = B->len,min = A_len > B_len ? B_len : A_len;

    int i;
    for(i = 0; i < min && A->elem[i] == B->elem[i]; i++);

    if(i < min){
        if(A->elem[i] < B->elem[i])
            return less;
        else
            return more;
    }
    else{
        if(i < A_len)
            return more;
        else if(i < B_len)
            return less;
        else
            return equal;
    }
    
}