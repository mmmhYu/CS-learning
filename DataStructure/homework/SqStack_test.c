#include"SqStack.h"

int main()
{
    printf("===== Init =====\n");

    SqStack s = InitStack(3);

    printf("empty = %d\n", StackEmpty(s));
    printf("length = %zu\n", StackLen(s));


    printf("\n===== Push =====\n");

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    printf("empty = %d\n", StackEmpty(s));
    printf("length = %zu\n", StackLen(s));

    printf("stack: ");
    StackTrav(s, visit);
    printf("\n");


    printf("\n===== GetTop =====\n");

    printf("top = %d\n", GetTop(s));


    printf("\n===== Pop =====\n");

    Pop(&s);

    printf("length = %zu\n", StackLen(s));
    printf("top = %d\n", GetTop(s));

    printf("stack: ");
    StackTrav(s, visit);
    printf("\n");


    printf("\n===== Push Again =====\n");

    Push(&s, 40);
    Push(&s, 50);

    printf("length = %zu\n", StackLen(s));

    printf("stack: ");
    StackTrav(s, visit);
    printf("\n");


    printf("\n===== Realloc Test =====\n");

    // 初始容量只有3，这里继续Push，测试自动扩容
    Push(&s, 60);
    Push(&s, 70);
    Push(&s, 80);
    Push(&s, 90);

    printf("length = %zu\n", StackLen(s));
    printf("size = %d\n", s.size);
    printf("top = %d\n", GetTop(s));

    printf("stack: ");
    StackTrav(s, visit);
    printf("\n");


    printf("\n===== Pop All =====\n");

    while(!StackEmpty(s)){
        printf("pop: %d\n", GetTop(s));
        Pop(&s);
    }

    printf("empty = %d\n", StackEmpty(s));
    printf("length = %zu\n", StackLen(s));


    printf("\n===== Clear =====\n");

    ClearStack(&s);

    printf("base = %p\n", (void*)s.base);
    printf("top  = %p\n", (void*)s.top);
    printf("size = %d\n", s.size);

    return 0;
}