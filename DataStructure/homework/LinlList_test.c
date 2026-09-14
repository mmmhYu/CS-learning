#include"LinkList.h"

int main(){

    // 1. 初始化
    LinkList L = InitList();

    printf("===== Init =====\n");
    printf("empty = %d\n", ListEmpty(L));
    printf("length = %d\n", ListLen(L));


    // 2. 插入
    printf("\n===== Insert =====\n");

    InsertElem(L, 1, 10);
    InsertElem(L, 2, 20);
    InsertElem(L, 3, 30);
    InsertElem(L, 4, 40);

    print_List(L);
    printf("\n");

    printf("length = %d\n", ListLen(L));


    // 3. 在中间插入
    printf("\n===== Insert Middle =====\n");

    InsertElem(L, 3, 25);

    print_List(L);
    printf("\n");

    // 预期：
    // 10 20 25 30 40


    // 4. GetElem
    printf("\n===== GetElem =====\n");

    printf("1st = %d\n", GetElem(L, 1));
    printf("3rd = %d\n", GetElem(L, 3));
    printf("5th = %d\n", GetElem(L, 5));


    // 5. LocateElem
    printf("\n===== LocateElem =====\n");

    printf("25 position = %d\n",
           LocateElem(L, 25, equal));

    printf("40 position = %d\n",
           LocateElem(L, 40, equal));

    printf("99 position = %d\n",
           LocateElem(L, 99, equal));


    // 6. 前驱、后继
    printf("\n===== Prev / Next =====\n");

    printf("Prev of 25 = %d\n", PrevElem(L, 25));
    printf("Next of 25 = %d\n", NextElem(L, 25));

    printf("Prev of 40 = %d\n", PrevElem(L, 40));
    printf("Next of 10 = %d\n", NextElem(L, 10));


    // 7. 删除中间结点
    printf("\n===== Delete Middle =====\n");

    ListDelete(L, 3);

    print_List(L);
    printf("\n");

    // 预期：
    // 10 20 30 40


    // 8. 删除第一个结点
    printf("\n===== Delete First =====\n");

    ListDelete(L, 1);

    print_List(L);
    printf("\n");

    // 预期：
    // 20 30 40


    // 9. 删除最后一个结点
    printf("\n===== Delete Last =====\n");

    ListDelete(L, 3);

    print_List(L);
    printf("\n");

    // 预期：
    // 20 30

    printf("length = %d\n", ListLen(L));


    // 10. 清空
    printf("\n===== FreeList =====\n");

    FreeList(&L);

    printf("empty = %d\n", ListEmpty(L));
    printf("length = %d\n", ListLen(L));

    return 0;
}