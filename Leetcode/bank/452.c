#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int my_cmp(const void *a, const void *b){
    int *pa = *(int**)a, *pb = *(int**)b;
    if(pa[1] > pb[1])
        return 1;
    else if(pa[1] < pb[1])
        return -1;
    else
        return 0;
}

/*int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), my_cmp);
    int count = 0, cut, n = pointsSize;
    while(pointsSize > 0){
        count++;
        int **p = points;
        while(*p == NULL)
            p++;
        cut = p[0][1];
        while(p < points+n){
            if(*p && p[0][0] <= cut){
                *p = NULL;
                pointsSize--;
            }
            p++;
        }
    }
    return count;
}*/

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if(!pointsSize)
        return 0;
    qsort(points, pointsSize, sizeof(int*), my_cmp);
    int count = 1,cut = points[0][1];
    int **p = points,**dst = points + pointsSize;
    while(pointsSize > 0){
        if(p[0][0] > cut){
            count++;
            cut = p[0][1];
        }
        pointsSize--;
        p++;
    }
    return count;
}

int main()
{
    // 测试数据:
    // [[10,16],[2,8],[1,6],[7,12]]
    int pointsSize = 4;

    int **points = malloc(pointsSize * sizeof(int *));

    for (int i = 0; i < pointsSize; i++) {
        points[i] = malloc(2 * sizeof(int));
    }

    points[0][0] = 10;
    points[0][1] = 16;

    points[1][0] = 2;
    points[1][1] = 8;

    points[2][0] = 1;
    points[2][1] = 6;

    points[3][0] = 7;
    points[3][1] = 12;


    int *pointsColSize = malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
    }

    int ans = findMinArrowShots(points, pointsSize, pointsColSize);

    printf("answer = %d\n", ans);


    // 释放内存
    for (int i = 0; i < pointsSize; i++) {
        free(points[i]);
    }

    free(points);
    free(pointsColSize);


    return 0;
}