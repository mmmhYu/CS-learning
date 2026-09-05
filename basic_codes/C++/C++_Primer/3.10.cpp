#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    string s;

    cin >> s;

    for(char c:s){
        if(!ispunct(c))
            cout << c;
    }
    cout << endl;

}