#include<stdio.h>
#include<stdlib.h>

typedef struct MemoryBlock{
    struct MemoryBlock *next;
}MemoryBlock;

typedef struct Static_Pool{
    void *pool;
    MemoryBlock *first_free;
    int Block_Size;
    int Pool_Size;
}Static_Pool;

void *init(int size,int num){
    Static_Pool *static_pool = (Static_Pool*)malloc(sizeof(Static_Pool));
    static_pool->Block_Size = size>sizeof(MemoryBlock*) ? size : sizeof(MemoryBlock*);
    //这里最好是sizeof(MemoryBlock) 这里比较特殊 结构体里面只存了一个指针 所以是一个意思
    static_pool->Pool_Size = num;
    static_pool->pool = malloc(size*num);
    static_pool->first_free = static_pool->pool;
    MemoryBlock *cur = (MemoryBlock*)static_pool->first_free;
    //这样的循环次数多了一次 就会导致最后一个结点指向的是 结束后的第一个地址
    //cur也是指向这个地址 但是修改cur的值 不等于修改最后一个节点的指向
    //也就是说最后一个节点并没有指向NULL
    //本质是要修改最后一个结点指向的地址 也就是最后一个结点存储的内容 这里修改cur
    //哪怕是在这个函数里面 也并没有修改最后一个结点指向的值 他依然指向那个最后面的地址
    //最后一个结点指向的地址，是存储在“最后一个结点的 next 成员”里的；
    //而 cur 只是一个额外的指针变量，它自己存储的地址变化，不会影响 next。
    //根本错误：想通过修改指针的值，修改他指向数据的值，即：
    //int a,b,*p = &a; p = &b;a的值不会改变 这其实是很简单的想法
    //倒也不是 其实是错在这里：a=b b=c 但是在程序语句里面a!=c
    //这里就是 我先建立最后一个结点->最后的cur 然后cur = NULL 
    //但是并不代表最后一个结点->NULL
    //实质上还是循环多了一次
    while(cur<(MemoryBlock*)(static_pool->first_free+size*num)){
        cur->next = (MemoryBlock*)(cur+static_pool->Block_Size);
        cur = cur->next;
    }
    cur = NULL;//是错的
    return static_pool;
}

void* pool_alloc(Static_Pool *sp){
    if(!sp->first_free)
        return NULL;
    Static_Pool *p = sp->first_free;
    sp->first_free = sp->first_free->next;
    return p;
}

void pool_free(Static_Pool *sp,void *p){
    //应该需要判断在不在内存池里面吧》  
    //if(p<sp->pool || p>(sp->pool+sp->s))
    MemoryBlock *free = (MemoryBlock*)p;
    free->next = sp->first_free;
    sp->first_free = free;
}
