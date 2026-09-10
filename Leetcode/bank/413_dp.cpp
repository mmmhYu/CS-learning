#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;

        int dp = 0,sum = 0;

        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                sum += ++dp;
            else
                dp = 0;
        }

        return sum;
    }
};

int main() {
    Solution s;

    vector<int> nums1 = {1, 2, 3, 4};
    cout << s.numberOfArithmeticSlices(nums1) << endl;  // 3

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << s.numberOfArithmeticSlices(nums2) << endl;  // 6

    vector<int> nums3 = {1, 3, 5, 7, 9};
    cout << s.numberOfArithmeticSlices(nums3) << endl;  // 6

    vector<int> nums4 = {1, 2, 3, 8, 9, 10};
    cout << s.numberOfArithmeticSlices(nums4) << endl;  // 2

    vector<int> nums5 = {7, 7, 7, 7};
    cout << s.numberOfArithmeticSlices(nums5) << endl;  // 3

    vector<int> nums6 = {1, 2};
    cout << s.numberOfArithmeticSlices(nums6) << endl;  // 0

    return 0;
}