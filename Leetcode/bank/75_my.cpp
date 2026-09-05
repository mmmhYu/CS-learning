#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0,r = nums.size()-1;

        while(l < r){
            while(l < r && nums[l] == 0)
                l++;
            
            while(l < r && nums[r] != 0)
                r--;

            if(l == r)
                break;

            swap(nums[l],nums[r]);

        }

        r = nums.size()-1;

        while(l < r){
            while(l < r && nums[l] == 1)
                l++;
            
            while(l < r && nums[r] == 2)
                r--;

            if(l == r)
                break;

            swap(nums[l],nums[r]);
        }
    }
};

int main(){
    vector<int> arr = {0,2,1,2,1,0,0,1,1,1,2,0,1,2,1,0};
    Solution s;
    s.sortColors(arr);
    for(int x:arr)
        cout << x << " ";
}