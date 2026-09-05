#include<vector>
#include<utility>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans;
        vector<int> path;
        backsource(n,k,0,ans,path);
        return ans;
    }

    void backsource(int n,int k,int size,vector<vector<int>>& ans,vector<int>& path){
        if(size == k){
            ans.push_back(path);
            return;
        }

        for(int i = size ? path[size-1]+1 : 1; i <= n; i++){
            path.push_back(i);
            backsource(n,k,size+1,ans,path);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;

    int n = 4;
    int k = 2;

    vector<vector<int>> result = s.combine(n, k);

    for (const auto& v : result) {
        cout << "[";
        for (int x : v)
            cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}