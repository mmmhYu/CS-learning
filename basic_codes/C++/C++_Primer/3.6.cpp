#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    string str = "hnfANFofqnNFUEUOfn";

    for(char i = 0; i < str.size(); i++)
        str[i] = 'A';

    for(auto x:str)
        cout << x;
    cout << endl;
    
    for(auto x:str)
        cout << x;
    cout << endl;

    for(char &c : str)
        c = toupper(c);
    cout << str << endl;

    for(int i = 0; i < str.size(); i++)
        str[i] = 'X';
    cout << str << endl;

    for(char &c : str)
        c = 'Y';
    cout << str << endl;


    
}