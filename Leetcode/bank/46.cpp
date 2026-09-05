#include<vector>
#include<utility>
#include<iostream>
using namespace std;

class Solution {
public:
    int n;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        n = nums.size();

        backtracking(nums,result,0);

        return result;
    }

    void backtracking(vector<int>& nums,vector<vector<int>>& result,int index){
        if(index == n-1){
            result.push_back(nums);
            return;
        }
            
        for(int i = index; i < n; i++){
            swap(nums[i],nums[index]);
            backtracking(nums,result,index+1);
            swap(nums[i],nums[index]);
        }
        
    }
};

int main(){
    vector <int> nums{1,2,3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int x:ans[i])
            cout << x;
        cout << endl; 
    }
}