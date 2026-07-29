#include<stdio.h>
#include<stdlib.h>

int my_cmp(const void *a,const void *b){
    int *pa = *(int **)a,*pb = *(int **)b;
    return pa[1]-pb[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if(intervalsSize == 0 || intervalsSize == 1)
        return 0;
    qsort(intervals,intervalsSize,sizeof(int*),my_cmp);
    int count = 1, i = 1, k = 0;
    while(i < intervalsSize){
        if(intervals[i][0] >= intervals[k][1]){
            count++;
            k = i;
        }
        i++;
    }
    return intervalsSize - count;
}

int main(){
    int intervalsSize = 4;

    // 创建 int**
    int **intervals = malloc(intervalsSize * sizeof(int *));

    for(int i = 0; i < intervalsSize; i++){
        intervals[i] = malloc(2 * sizeof(int));
    }


    // [[1,2],[2,3],[3,4],[1,3]]
    intervals[0][0] = 1;
    intervals[0][1] = 2;

    intervals[1][0] = 2;
    intervals[1][1] = 3;

    intervals[2][0] = 3;
    intervals[2][1] = 4;

    intervals[3][0] = 1;
    intervals[3][1] = 3;


    int *intervalsColSize = malloc(intervalsSize * sizeof(int));

    for(int i = 0; i < intervalsSize; i++){
        intervalsColSize[i] = 2;
    }
    int ans = eraseOverlapIntervals(intervals, intervalsSize, intervalsColSize);
    printf("%d\n",ans);
    for(int i = 0; i < intervalsSize; i++){
        free(intervals[i]);
    }
    free(intervals);
    free(intervalsColSize);
    return 0;
}