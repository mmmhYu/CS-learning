#include<stdio.h>
#include<stdlib.h>
#define my_size 10

typedef struct{
    int arr[my_size];
    int top;
}sqstack;

sqstack* init(){
    sqstack *s;
    s = malloc(sizeof(sqstack));
    if(!s)
        return NULL;
    s->top = 0;
    return s;
}

int destroy(sqstack **s){
    if(!s || !*s)//注意两次解引用的顺序
        return 0;
    free(*s);
    *s = NULL;
    return 1;
}

int is_empty(sqstack *s){
    if (!s){
        printf("nullptr!\n");
        return 0;
    }
    
    return s->top == 0;
}

int is_full(sqstack *s){
    if (!s){
        printf("nullptr!\n");
        return 0;
    }
    
    return s->top >= my_size;
}

int push(sqstack *s,int val){
    /*if(!s){
        printf("nullptr!\n");
        return -1;
    }*/
        

    if(is_full(s)){
        printf("FULL!\n");
        return 0;
    }
        
    s->arr[s->top++] = val;
    return 1;
}

int pop(sqstack *s){
    /*if(!s){
        printf("nullptr!\n");
        return -1;
    }*/

    if(is_empty(s)){
        printf("EMPTY!");
        return 0;
    }

    int elem = s->arr[--s->top];
    return elem;//返回删除的值
}

int change(sqstack *s, int new_val, int index){
    
    if(is_empty(s))
        return 0;
    
    if(index >= s->top){
        printf("overload!\n");
        return -1;
    }
    int org_val = s->arr[index-1];
    s->arr[index-1] = new_val;
    return org_val;
}

int get_top(sqstack *s){
    if(is_empty(s))
        return -142857;//随便来一个了
    
    return s->arr[s->top-1];
    
}
//对于这里所有需要传回值的函数，都有一个通用的改进措施：用指针传值，函数传递状态
