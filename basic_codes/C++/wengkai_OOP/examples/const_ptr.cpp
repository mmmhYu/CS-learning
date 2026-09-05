#include<iostream>
using namespace std;
int main(){
    const int a=1,b = 2;
    
    
    
//    int *p = &a;
    const int *q = &b;
    //这里的标准是左值相比右值，权限不更大
//    *q = 3;
//    cout << *p << endl;
    cout << *q << endl;
    return 0;
}