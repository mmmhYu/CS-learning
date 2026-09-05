#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int n;

    vector<vector<int>> permute(vector<int>& nums){
        n = nums.size();
        vector<vector<int>> ans;
        backsource(nums,0,ans);
        return ans;
    }

    void backsource(vector<int>& nums,int index,vector<vector<int>>& ans){
        if(index == n){
            ans.push_back(nums);
            return;
        }
            
        for(int k = index; k < n; k++){
            swap(nums[index],nums[k]);
            backsource(nums,index+1,ans);
            swap(nums[index],nums[k]);
        }
    }
};