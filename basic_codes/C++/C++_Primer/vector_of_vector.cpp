#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {4,5,6};
    vector<int> arr3 = {7,8,9,0};
    vector<vector<int> > arr = {arr1,arr2,arr3};

    for(vector<vector<int> >::iterator it = arr.begin(); it != arr.end(); it++){
        for(vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++)
            cout << *itt << " ";
        cout << endl;
    }
}