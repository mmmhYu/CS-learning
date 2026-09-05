#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0,arr[3]={0};
        for(int x:nums)
            arr[x]++;
        int index = 0;
        for(i = 0; i < arr[0]; i++)
            nums[index++] = 0;

        for(i = 0; i < arr[1]; i++)
            nums[index++] = 1;

        for(i = 0; i < arr[2]; i++)
            nums[index++] = 2;
    }
};

int main(){
    vector<int> arr = {0,2,1,2,1,0,0,1,1,1,2,0,1,2,1,0};
    Solution s;
    s.sortColors(arr);
    for(int x:arr)
        cout << x << " ";
}