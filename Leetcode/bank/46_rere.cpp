#include<utility>
#include<vector>
using namespace std;

class Solution {
public:
    int n;

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        backtracking(ans,nums,0);
        return ans;
    }

    void backtracking(vector<vector<int>>& ans,vector<int>& nums,int  cur){
        if(cur == n){
            ans.push_back(nums);
            return;
        }

        for(int i = cur; i < n; i++){
            swap(nums[cur],nums[i]);
            backtracking(ans,nums,cur+1);
            swap(nums[cur],nums[i]);
        }
    }
};