#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void my_swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void print_vector(vector<T>& arr){
    for(T x:arr)
        cout << x << " ";
    
    cout << endl;
}

template <typename T>
void print_vector_promax(T& arr){
    int size = arr.size();
    for(int k = 0; k < size; k++)
        cout << arr[k] << " ";
    
    cout << endl;
}

int main(){
    vector<string> a = {"Hello World","谢谢你"},b = {"我是朱加一","world hello"};
    my_swap(a,b);
    print_vector_promax(a);
    print_vector_promax(b);

    string str = "Hello World!";
    print_vector_promax(str);

    return 0;
}