#include<vector>
#include<iostream>
using namespace std;

#define max(a,b) a > b ? a : b

class Solution {
public:
    int rob(vector<int>& nums){
        vector<int> dp(2);

        if(nums.size() == 1)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i = 2; i < nums.size(); i++)
            dp[i%2] = max((nums[i] + dp[i%2]),(dp[(i-1) % 2]));

        return dp[(nums.size()-1) % 2];
    }
};

int main() {
    Solution s;

    vector<int> nums = {6, 7, 1, 30, 8, 2, 4};

    cout << s.rob(nums) << endl;

    return 0;
}