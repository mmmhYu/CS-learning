#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0,l = -1,r = nums.size();

        while(i < r){

            if(nums[i] == 1)
                i++;
            else if(nums[i] == 0)
                swap(nums[++l],nums[i++]);
            else{
                swap(nums[--r],nums[i]);
            }
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