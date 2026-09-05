#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur(k,0);
        int count = 0;
        backtracking(n,k,count,1,cur,ans);
        return ans;
    }

    void backtracking(int n,int k,int& count,int index,vector<int>& cur,vector<vector<int>>& ans){
        if(count == k){
            ans.push_back(cur);
            return;
        }

        for(int i = index; i <= n; i++){
            cur[count++] = i;
            backtracking(n,k,count,i+1,cur,ans);
            count--;
        }
    }
};