#include<iostream>

using namespace std;

int& f(int &x){
	return x;
}

int main(){
	int x;
	f(x) = 10;//x = 10
    cout << x << endl;
}
