#include<iostream>
using namespace std;

int& f(int &x){
	return x;
}

int main(){
	int x;
	f(x) = 10;//x = 10
    cout << x << endl;

    int y = 9;
    int &a=x;
    int &b=y;   //合法，本质等价于int &b=x
    b = a;
    cout << a << b << endl;
    cout << x << y << endl;
}
