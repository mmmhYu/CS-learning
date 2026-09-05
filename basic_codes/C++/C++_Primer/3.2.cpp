#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    string s;

    while(cin >> s){
        if(s == "quit")
            break;

        cout << s <<endl;
    }
    
    //这个清理cin缓冲区的函数，说实话不是很理解,也不需要理解//
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin,s);

    cout << s << endl;

}