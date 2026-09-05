#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print_vector_promax(T& arr){
    int size = arr.size();

    for(int k = 0; k < size; k++)
        cout << arr[k];
    cout << endl;
}

template <typename A,typename B>
void biprint(A a,B b){
    print_vector_promax(a);
    print_vector_promax(b);
}

int main(){
    vector<int> arr = {1,2,3};
    string str = "Hello World!";
    //自动类型推导
    biprint(arr,str);
    //显式类型指定
    biprint<vector<int>,string>(arr,str);
}

