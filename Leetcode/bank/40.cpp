#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int tmp_sum = 0;
        vector<int> path;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());

        backTrack(candidates,ans,path,0,tmp_sum,target);

        return ans;
    }

    void backTrack(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& path,int idx,int tmp_sum,int target){

        for(int i = idx; i < candidates.size(); i++){

            path.push_back(candidates[i]);
            tmp_sum += candidates[i];

            if(tmp_sum < target){
                backTrack(candidates,ans,path,i+1,tmp_sum,target);
                tmp_sum -= candidates[i];
                path.pop_back();
            }
            else if(tmp_sum == target){
                ans.push_back(path);
                tmp_sum -= candidates[i];
                path.pop_back();
                return;
            }
            else{
                tmp_sum -= candidates[i];
                path.pop_back();
                break;
            }   
            while(i+1 < candidates.size() && candidates[i+1] == candidates[i])
                i++;
        }
    }
};

// 这里放你的 Solution 类

int main() {
    Solution s;

    // Test 1
    // nums = [10,1,2,7,6,1,5], target = 8
    // Expected:
    // [1,1,6]
    // [1,2,5]
    // [1,7]
    // [2,6]
    vector<int> nums1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;

    auto ans1 = s.combinationSum2(nums1, target1);

    cout << "Test 1:" << endl;
    for (auto& v : ans1) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }


    // Test 2
    // nums = [2,5,2,1,2], target = 5
    // Expected:
    // [1,2,2]
    // [5]
    vector<int> nums2 = {2, 5, 2, 1, 2};
    int target2 = 5;

    auto ans2 = s.combinationSum2(nums2, target2);

    cout << "\nTest 2:" << endl;
    for (auto& v : ans2) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }


    // Test 3
    // 全部相同
    // nums = [1,1,1,1], target = 2
    // Expected:
    // [1,1]
    vector<int> nums3 = {1, 1, 1, 1};
    int target3 = 2;

    auto ans3 = s.combinationSum2(nums3, target3);

    cout << "\nTest 3:" << endl;
    for (auto& v : ans3) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }


    // Test 4
    // 无解
    vector<int> nums4 = {3, 4, 5};
    int target4 = 2;

    auto ans4 = s.combinationSum2(nums4, target4);

    cout << "\nTest 4:" << endl;
    cout << "Total: " << ans4.size() << endl;


    // Test 5
    // 多组重复
    // nums = [1,1,2,2,3], target = 4
    // Expected:
    // [1,1,2]
    // [1,3]
    // [2,2]
    vector<int> nums5 = {1, 1, 2, 2, 3};
    int target5 = 4;

    auto ans5 = s.combinationSum2(nums5, target5);

    cout << "\nTest 5:" << endl;
    for (auto& v : ans5) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}