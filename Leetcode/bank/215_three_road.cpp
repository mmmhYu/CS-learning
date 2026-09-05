#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_sort(nums,0,nums.size()-1,nums.size()-k);
    }

    int quick_sort(vector<int>& nums,int l, int r,int k){

        if(l >= r)
            return nums[l];

        int i = l,left = l-1,right = r+1,pivot = nums[l];

        while(i < right){
            if(nums[i] == pivot)
                i++;
            else if(nums[i] < pivot)
                swap(nums[i++],nums[++left]);
            else
                swap(nums[--right],nums[i]);
        }
        
        if(right <= k)
            return quick_sort(nums,right,r,k);
        else if(right > k && k > left)
            return pivot;
        else
            return quick_sort(nums,l,left,k);
    }
};

int main(){
    Solution s;
    vector<int> arr{3,2,1,5,6,4};
    cout << s.findKthLargest(arr,2) << endl;
}