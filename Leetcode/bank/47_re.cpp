#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<bool> vis;

    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(),nums.end());
        vis.resize(nums.size());

        backTracking(nums,path,ans,0);
        return ans;
    }

    void backTracking(vector<int>& nums,vector<int>& path,vector<vector<int>>& ans,int index){
        if(index == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(vis[i] || (i > 0 && nums[i] == nums[i-1] && vis[i]))
                continue;

            vis[i] = true;
            path.push_back(nums[i]);
            backTracking(nums,path,ans,index+1);
            path.pop_back();
            vis[i] = false;
        }
    }
};

void printAns(const vector<vector<int>>& ans) {
    for (const auto& v : ans) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]" << endl;
    }
    cout << "Total: " << ans.size() << endl;
}

int main() {
    Solution s;

    // Test 1
    // Expected:
    // [1,1,2]
    // [1,2,1]
    // [2,1,1]
    vector<int> nums1 = {1, 1, 2};
    cout << "Test 1:" << endl;
    printAns(s.permuteUnique(nums1));


    // Test 2：没有重复
    // 一共 6 种
    vector<int> nums2 = {1, 2, 3};
    cout << "\nTest 2:" << endl;
    printAns(s.permuteUnique(nums2));


    // Test 3：全部相同
    // Expected: 只有一种
    // [2,2,2]
    vector<int> nums3 = {2, 2, 2};
    cout << "\nTest 3:" << endl;
    printAns(s.permuteUnique(nums3));


    // Test 4：两组重复元素
    // 一共 4! / (2! * 2!) = 6 种
    vector<int> nums4 = {1, 1, 2, 2};
    cout << "\nTest 4:" << endl;
    printAns(s.permuteUnique(nums4));


    // Test 5：三个相同 + 一个不同
    // 一共 4 种
    vector<int> nums5 = {1, 1, 1, 2};
    cout << "\nTest 5:" << endl;
    printAns(s.permuteUnique(nums5));

    return 0;
}