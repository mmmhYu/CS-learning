#include<iostream>

using namespace std;

void f(int x)
{
    cout << "reference";
}

void f(int& x)
{
    cout << "const reference";
}

int main(){
    int a = 10;
    int &r = a;
    //f(r);
}