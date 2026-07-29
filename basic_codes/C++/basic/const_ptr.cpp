#include<iostream>
using namespace std;
int main(){
    int a=1,b=2;
    const int *p=&a;
    int *q = &b;
    p = q;
    //这里的标准是 左值在赋值之后 “权限“不减少
    *q = 3;
    cout << *p << endl;
    cout << *q << endl;
    return 0;
}