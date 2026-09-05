#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define POOL_SIZE 10
#define BLOCK_SIZE 32

typedef struct{
    uint8_t data[POOL_SIZE][BLOCK_SIZE];
    int next_free[POOL_SIZE];
    int first_free;
    int free_count;
}StaticPool;

void init(StaticPool *pool){
    for(int i = 0; i < POOL_SIZE-1; i++){
        pool->next_free[i] = i+1;
    }
    pool->next_free[POOL_SIZE-1] = -1;
    pool->first_free = 0;
    pool->free_count = POOL_SIZE;
}

void* pool_alloc(StaticPool *pool){
    if(pool->first_free = -1){
        return NULL;
    }
    void *res = &(pool->data[pool->first_free]);
    pool->first_free = pool->next_free[pool->first_free];
    pool->free_count--;
    return res;
}

void pool_free(StaticPool *pool, void *ptr){
    int new_free = ((uint8_t*)ptr -(uint8_t*)pool->data)/BLOCK_SIZE;
    if(pool->free_count == 0 || new_free >= POOL_SIZE){
        printf("Error!");
        return;
    }
    pool->next_free[new_free] = pool->first_free;
    pool->first_free = new_free;
    pool->free_count++;
}


