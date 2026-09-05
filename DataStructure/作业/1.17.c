#include<stdio.h>

int fibonacci(int k ,int m){
    if(k <= 0 || m < 0)
        return -1;

    if(m < k-1)
        return 0;
    else if(m == k-1)
        return 1;
    else{
        int tmp = 0;
        for(int i = m-1; i >= m-k; i--){
            tmp += fibonacci(k,i);
        }
        return tmp;
    }
}

//但是这样递归会重复算很多，下面这个看起来臃肿一点但是应该更快？
int fibonacci_usingarr(int k ,int m){
    if(k <= 0 || m < 0)
        return -1;

    int arr[100] = {0};//C只能这样写了T_T
    arr[k-1] = arr[k] = 1;

    if(m < k)
        return arr[m];
    else{
        int sum_of_k = 1;
        for(int i = k+1; i <= m; i++){
            sum_of_k += (arr[i-1] - arr[i-k-1]);
            arr[i] = sum_of_k;
            }
        }

        return arr[m];
}

int main(){
    for(int i = 0; i < 10; i++)
        printf("%d\n", fibonacci_usingarr(3,i));
}