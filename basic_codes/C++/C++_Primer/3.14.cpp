#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    vector<string> arr;
    string x;

    while(cin >> x){
        arr.push_back(x);
    }

    for(string &x : arr){
        for(char& c : x)
            c = toupper(c);
    }
    
    for(string x : arr)
        cout << x << " ";
    cout << endl;
}