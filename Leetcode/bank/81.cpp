#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
//边界条件还是错了好多，另外考虑一下有没有必要说直接在循环里面增加return判断
//结束之后只return false
//另外，尝试一下左闭右闭
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1,mid;

        while(l < r){
            mid = l + (r-l)/2;

            if(nums[mid] < nums[r]){
                if(target <= nums[r] && target > nums[mid])
                    l = mid+1;
                else
                    r = mid;
            }
            else if(nums[mid] > nums[r]){
                if(nums[l] <= target && nums[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            else{
                if(nums[mid] == target)
                    return true;
                else
                    r--;
            }
        }
        if(nums[l] == target)
            return true;

        return false;
    }
};

int main(){
    vector<int> test{2,2,2,3,2,2,2};
    Solution slt;
    cout << slt.search(test,3) << endl;
}