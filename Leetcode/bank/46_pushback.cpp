#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;

        backTracking(nums,path,ans,0);
    }

    void backTracking(vector<int>& nums,vector<int>& path,vector<vector<int>>& ans,int index){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);    
        }
    }
};