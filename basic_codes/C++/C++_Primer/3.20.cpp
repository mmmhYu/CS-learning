#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

int main(){
    vector<int> arr;
    int x;

    while(cin >> x)
        arr.push_back(x);

    vector<int>::size_type num = arr.size(); 
    for(int i = 0; i < (num+1)/2; i++)
        cout << arr[i] + arr[num-1-i] << " ";
    cout << endl;

}
