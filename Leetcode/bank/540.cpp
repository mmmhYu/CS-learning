#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/*class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size(),mid;

        if(r==1 || nums[r-1] != nums[r-2])
            return nums[r-1];

        while(l < r){
            mid = l+(r-l)/2;

            if(!mid || nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                return nums[mid];
                
            if((!(mid%2)&&nums[mid]==nums[mid-1]) || (mid%2)&&nums[mid] == nums[mid+1])
                r = mid;
            else
                l = mid+1;//这里好像会有问题，如果mid刚好是单个的(所以前面加了一个)
                
        }
        return nums[l];
    }
};*/

//优化版本
//优化方向：只有确保mid不是的时候，才把l=mid+1
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size(),mid;

        if(r==1)
            return nums[0];

        while(l < r){
            mid = l+(r-l)/2;
                
            if(nums[mid] == nums[mid^1])
                l = mid + 1;
            else
                r = mid;
                
        }
        return nums[l];
    }
};

int main(){
    vector<int> test{1,2,2,3,3};
    Solution s;

    cout << s.singleNonDuplicate(test) << endl;
}