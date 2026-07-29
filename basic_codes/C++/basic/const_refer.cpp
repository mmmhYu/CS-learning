#include<iostream>
using namespace std;

int main(){
    int n = 5;
    const int &r = n;
    n = 4;
    cout<<r<<endl;
    return 0;
}