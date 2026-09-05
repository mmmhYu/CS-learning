#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    string s1,s2;

    cin >> s1 >> s2;
    
    //这里多此一举了，不如和下面if并到一起，反而要判断两次了这样
    cout << (s1 == s2 ? "same" : "different") << endl;

    if(s1 != s2){
        cout << "字典序较大的字符串是：" << (s1 > s2 ? s1 : s2) << endl;
        if(s1.size() != s2.size())
            cout << "长度较长的字符串是：" << (s1.size() < s2.size() ? s2 : s1) << endl;
        else
            cout << "两字符串长度相等！" << endl;
    }
}