#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
void print_arr(T (&arr),int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//就是说，参数传递如果用引用，而且是数组的引用，需要明确元素个数
//因为这才是完整的类型，是引用所需要的
void my_normal_print(int arr[],int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T,unsigned M>
void print_ARRAY(const T (&arr)[M]){
    for(int i = 0; i < M; i++)
        cout << arr[i];
    cout << endl;
}

int main(){
    int arr[3] = {1,2,3};
    //print_arr(arr,3);

    print_ARRAY(arr);//这里不是const也可以，因为可以int->const int，是合法的
    print_ARRAY("HI!");//在编译器看来，HI！就是const char [4]，注意末尾有个0
}
