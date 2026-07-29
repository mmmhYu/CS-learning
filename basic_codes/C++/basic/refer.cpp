#include<iostream>
using namespace std;

int main(){
    int a=1;
    int & b = a;
    b = 7;
    cout<<a<<endl;
}