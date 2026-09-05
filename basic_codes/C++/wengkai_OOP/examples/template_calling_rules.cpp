#include<iostream>
#include<string>
#include<vector>
using namespace std;

//标准函数
void func(int a,int b){
    cout << "normal int int" << endl;
}

//如下函数用来解释，当普通函数和函数模版都匹配，优先调用普通函数
template <typename T>
void func(T a,T b){
    cout << "template T T" << endl;
}

//如下函数用来解释，当模版更加匹配的时候，会有先调用函数模版
template <typename T,typename TT>
void func(T a,TT b){
    cout << "template T TT" << endl;
}

//这两个函数也说明，函数模版可以重载
//当然重载的方式不止这一种，这只是类型列表，函数的参数列表也可以构成重载改

int main(){
    int a = 1,b = 2;
    char c = 'a';

    cout << "for a and b" << endl;
    func(a,b);
    cout << endl;

    cout << "if empty explicit a and b" << endl;
    func<>(a,b);
    cout << endl;

    cout << "if explicit a and b" << endl;
    func<int>(a,b);
    cout << endl;

    cout << "for a and c" << endl;
    func(a,c);
    cout << endl;

    cout << "if explicit int a and c" << endl;
    func<int>(a,c);
    cout << endl;
    cout << "if explicit char a and c" << endl;
    func<char>(a,c);//解释：这里只显式指定第一个参数，模版2更匹配
    cout << endl;
    cout << "if explicit int c and a" << endl;
    func<int>(c,a);    
    cout << endl;
    cout << "if explicit char c and a" << endl;
    func<char>(c,a);    
    cout << endl;

    return 0;
}