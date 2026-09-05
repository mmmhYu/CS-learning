#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,numsSize = nums.size(),r = numsSize-1,mid;
        while(l <= r){
            mid = l+(r-l)/2;

            if(nums[mid] == target)
                return true;

            if(nums[mid] >= nums[l]){

                if(target >= nums[l] && target <= nums[mid])
                    r = mid;
                else
                    l = mid+1;

            }
            else{

                if(target >= nums[mid] && target <= nums[r])
                    l = mid;
                else
                    r = mid-1;

            }
        }
        return false;
    }
};