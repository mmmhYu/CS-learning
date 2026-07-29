#include<stdio.h>
#include<stdlib.h>

int **gen(int n,int m){
    int **p;
    p = malloc(n*sizeof(int*));
    if(p == NULL){
        printf("failed\n");
        return NULL;
    }
    for(int i = 0;i < n;i++){
        *(p+i) = malloc(m*sizeof(int));
        if(*(p+i) == NULL){
            printf("failed\n");
            return NULL;
        }
    }
    return p;
}

void write_matrix(int **p,int n,int m){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",*(p+i)+j);
        }
    }
}

int sort(int **p,int k,int n,int m,int *cols,int *sum){
    int count = 0,temp_sum=0;
    for(int i=0;i<n;i++){
        temp_sum = 0;
        for(int j=0;j<m;j++){
            temp_sum += *(*(p+i)+j);
        }
        if(temp_sum >= k*m){
            cols[count] = i;
            sum[count++] = temp_sum;
        }
    }
    return count;
}

void free_matrix(int **p,int n){
    for(int i = 0;i<n;i++){
        free(*(p+i));
    }
    free(p);
}

int main(){
    int **matrix,n=0,m=0,k=0,count = 0,cols[50],sum[50];
    scanf("%d %d %d",&n,&m,&k);
    matrix = gen(n,m);

    if(matrix == NULL){
        printf("内存分配失败!\n");
        return 0;
    }

    write_matrix(matrix,n,m);
    count = sort(matrix,k,n,m,cols,sum);
    printf("%d\n",count);
    if(count == 0)
        printf("EMPTY\n");
    else{
        for(int i = 0;i < count;i++){
            printf("%d",sum[i]);
            for(int j = 0;j < m;j++){
                printf(" %d",matrix[cols[i]][j]);
            }
            printf("\n");
        }
    }
    free_matrix(matrix,n);
}