#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    cout << "please enter two ints" << endl;
    int v1,v2;
    cin >> v1 >> v2;
    int vm = v1 > v2 ? v2 : v1, vM = v1 < v2 ? v2 : v1;
    int index = vm;
    while(index <= vM){
        cout << index++ << endl;
    }
    return 0;
}