#include<stdio.h>
 
//定义结构体
typedef struct
 {
    int *List;
    int data_num;
    int Max_Num;
 }Linear_List;


//初始化
int init_list(Linear_List *l,int max){
    int a;
    if(max<=0)
        return 0;
    l->List = (int*)malloc(max*sizeof(int));
    l->data_num = 0;
    for(int i=0;i<max;i++)
        l->List[i] = 0;
    return 1;
}

//增加最大长度
int Increase_Size(Linear_List *l,int n){
    int *p;
    p=l->List;
    l->Max_Num += n;
    l->List = (int*)malloc((l->Max_Num)*sizeof(int));
    if(l->List == NULL && n<=0)
        return 0;
    for(int i=0;i<l->data_num;i++)
        l->List[i] = p[i];
    free(p);
    return 1;
}

//插入
int Insert(Linear_List *l,int k,int e){
    int i;
    if(i<1 || i>l->data_num || l->data_num == l->Max_Num)
        return 0;
    for(i=l->data_num;i>=k;i--)
        l->List[i]=l->List[i-1];
    l->List[k-1] = e;
    l->data_num += 1;
    return 1;
}

//删除
int Delete(Linear_List *l,int k,int *e){
    int i;
    if(k<1 || k>l->data_num)
        return 0;
    *e = l->List[k];
    for(i=k-1;i<l->data_num-1;i++)
        l->List[i]=l->List[i+1];
    l->data_num -= 1;
    l->List[l->data_num-1] = 0;
    return 1;
}
