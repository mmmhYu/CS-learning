#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int sum = 0, val = 0;
    while(cin >> val)
        sum += val;
    cout << "Sum is " << sum << endl;
    return 0;
}
//这里循环结束的条件：强制退出；输入非法（字符）；输入EOF/control+D
//后面两者的原理都是：读取失败，<<表达式错误流状，导致循环终止