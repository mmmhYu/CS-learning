#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0,sum = 0,diff = 0;

        if(nums.size() < 3)
            return 0;

        diff = nums[1]-nums[0];

        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == diff)
                sum += ++dp;
            else{
                diff = nums[i] - nums[i-1];
                dp = 0;
            }
        }

        return sum;

    }
};