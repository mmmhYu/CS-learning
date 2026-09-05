#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums,0,nums.size()-1,nums.size()-k);
    }

    int quick_sort(vector<int>& nums,int l, int r,int k){
        if(l >= r)
            return nums[l];
            
        int seed = rand()%(r-l+1)+l;
        int left = l,right = r,pivot = nums[seed];

        while(left < right){
            while(left < right && nums[right] >= pivot)
                right--;
            if(right == seed){
                right--;
                continue;
            }

            while(left < right && nums[left] <= pivot)
                left++;
            if(left == seed){
                left++;
                continue;
            }

            swap(nums[left],nums[right]);
        }

        swap(nums[seed],nums[left]);

        if(left < k)
            return quick_sort(nums,left+1,r,k);
        else
            return quick_sort(nums,l,left,k);
    }

    //用随机写，可以AC
    int quick_select(vector<int>& nums, int l, int r, int k){
        if (l >= r)
            return nums[l];

        int seed = rand() % (r - l + 1) + l;
        swap(nums[l], nums[seed]);

        int pivot = nums[l];
        int left = l, right = r;

        while (left < right) {
            while (left < right && nums[right] >= pivot)
                right--;

            nums[left] = nums[right];

            while (left < right && nums[left] <= pivot)
                left++;

            nums[right] = nums[left];
        }

        nums[left] = pivot;

        if (left == k)
            return nums[left];
        else if (left < k)
            return quick_select(nums, left + 1, r, k);
        else
            return quick_select(nums, l, left - 1, k);
    }
};

int main(){
    Solution s;
    vector<int> arr{3,2,1,1,1,1,1,1,1,1,1,1,1,-1,-2,-3};
    cout << s.findKthLargest(arr,2) << endl;
}
