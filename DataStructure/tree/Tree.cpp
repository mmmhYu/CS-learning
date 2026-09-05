#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

//双亲表示法
typedef struct node
{
    int val,parent;
}ptree_node;

typedef struct ptree
{
    int size;
    vector<ptree_node> arr;

    ptree(int num):size(num),arr(num){}    
}parent_tree;
//这样写是因为类的定义是一个声明

//或者这样
#define MaxSize 100
typedef struct
{
    int size;
    ptree_node arr[MaxSize];
}ptree;

//孩子表示法
typedef struct cnode
{
    int index;
    struct cnode *next;
}child_node;

typedef struct cTreenode
{
    int val;
    child_node *first_child;
}child_tree_node;

typedef struct cTree
{
    int n,r;//这里需要知道根的位置，主要是为了森林的情形做准备
    child_tree_node arr[MaxSize];
}child_tree;

//孩子兄弟表示法
typedef struct cbtreenode
{
    int val;
    struct cbtreenode *firstchild;
    struct cbtreenode *next_brother;
}child_brother_tree_node,*cbtree;

//孩子存储的先根遍历
void visit(child_tree_node node){
    cout << node.val << endl;
}

void rt_fir_view(child_tree_node& root,child_tree tree){

    visit(root);

    if(!root.first_child)
        return;
    
    child_tree_node node = tree.arr[root.first_child->index];
    child_node *p = root.first_child;

    while(p){
        rt_fir_view(node,tree);

        p = p->next;
        node = tree.arr[p->index];//最后一次循环报错！一定报错！！
    }
    //这样写就有个问题，最后一次循环，先把p置为nullptr，然后更新node，就错误了
    //最好这样写：进入循环，p不为nullptr，根据这个p去取node
    while(p){
        rt_fir_view(tree.arr[p->index],tree);
        p = p->next;
    }
    //所以node初始化是不必要的
    //其实前面if判断返回也是不必要的，因为第一次循环p就是firstchild
    //但是这样写比较符合规范？？

}
