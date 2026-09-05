#include<iostream>
using namespace std;

int main(){

    int n = 4;double f = 3.14;

    const int &r = n;
    const int &rr = 0;
    const int &rrr = n*3;
    const int &rf = f;
    //等价于：
    //tmp = (int)f;
    //const int &rf = tmp;
    //一般而言，这个tmp是不能作为一个“左值”出现在引用的右边的，但是因为const，延长其生存周期
    cout << r << " " << rr << " " << rrr << " " << rf << endl;

    return 0;
}