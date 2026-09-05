#include<iostream>


class A
{
private:
    int x;

public:
    A():x(10){}
};

int main()
{
    A a;
    int *p = (int*)&a;

    *p = 20;   // 错误
}