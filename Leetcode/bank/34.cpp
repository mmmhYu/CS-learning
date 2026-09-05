#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        vector<int> ans(2);
        //找左端点
        while(l < r){
            mid = l + (r-l)/2;

            if(nums[mid] >= target)
                r = mid;
            else
                l = mid+1;
        }

        if(nums[l] != target){
            ans[0] = ans[1] = -1;
            return ans;
        }

        ans[0] = l;
        //找右端点
        l=0;r=nums.size()-1;
        while(l <= r){
            mid = l + (r-l)/2;

            if(nums[mid] <= target)
                l = mid+1;
            else
                r = mid-1;
        }
        ans[1] = r;

        return ans;
    }
};