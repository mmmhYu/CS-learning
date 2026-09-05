#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int cnt = 1;
    while(cnt <= matrixSize && target > (*matrix)[*matrixColSize-1]){
        matrix++;
        cnt++;
    }
    if(cnt == matrixSize+1)
        return 0;
    for(int i = 0; i < *matrixColSize; i++){
        if((*matrix)[i] == target)
            return 1;
    }
    return 0;
}


int main() {
    int row = 3;

    int a0[] = {1, 3, 5, 7};
    int a1[] = {10, 11, 16, 20};
    int a2[] = {23, 30, 34, 60};

    int* matrix[] = {a0, a1, a2};

    int colSize[] = {4, 4, 4};

    int targets[] = {3, 13, 60, 1, 61};

    for (int i = 0; i < 5; i++) {
        int target = targets[i];

        bool ans = searchMatrix(matrix, row, colSize, target);

        printf("target = %d, result = %s\n",
               target,
               ans ? "true" : "false");
    }

    return 0;
}