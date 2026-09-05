#include<stdio.h>
#include<stdlib.h>

typedef struct BiT{
    int val,ltag,rtag;
    struct BiT *lchild,*rchild;    
}TreeNode,*Tree;

TreeNode *pre = NULL;

void visit(TreeNode *leave){

    leave->ltag = !leave->lchild;
    leave->rtag = !leave->rchild;

    printf("%d\n",leave->val);

    if(leave->ltag)
        leave->lchild = pre;

    if(pre && pre->rtag)
        pre->rchild = leave;

    pre = leave;
}

void see(Tree T){
    //严谨一点就先判断左右孩子指针是真的左右子树还是前驱后继
    if(T){
        if(!T->lchild)
            see(T->lchild);

        visit(T);

        if(!T->rchild)
            see(T->rchild);

    }
}

void clue_trans(Tree T){

    if(T){

        see(T);

        if(pre){
            pre->rtag = 1;
            pre->rchild = NULL;
        }

    }
    else{
        printf("NULL!\n");
    }

}
