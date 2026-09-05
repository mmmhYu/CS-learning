#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void my_swap(T &a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void my_sort(T arr[],int size){
    T max;
    int max_index;

    for(int i = 0; i < size-1; i++){
        max = arr[i];
        max_index = i;

        for(int j = i+1; j < size; j++){
            if(max < arr[j]){
                max_index = j;
                max = arr[j];
            }

        }

        my_swap(arr[i],arr[max_index]);

    }
}

int main(){
    string arr[3] = {"asdb","nyvs","csudv"};
    my_sort(arr,3);
    for(string x:arr)
        cout << x << " ";
}