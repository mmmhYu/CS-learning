#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<int>& nums,
         int idx,
         stack<int>& st,
         vector<int>& path,
         vector<vector<int>>& ans)
{
    if(path.size() == nums.size()){
        ans.push_back(path);
        return;
    }

    // 选择1：入栈
    if(idx < nums.size()){
        st.push(nums[idx]);

        dfs(nums, idx + 1, st, path, ans);

        st.pop();   // 回溯
    }

    // 选择2：出栈
    if(!st.empty()){
        int x = st.top();
        st.pop();

        path.push_back(x);

        dfs(nums, idx, st, path, ans);

        path.pop_back();
        st.push(x); // 回溯
    }
}



int main()
{
    vector<int> nums = {1, 2, 3};

    stack<int> st;
    vector<int> path;
    vector<vector<int>> ans;

    dfs(nums, 0, st, path, ans);

    cout << "Total: " << ans.size() << endl;

    for(const auto& seq : ans){
        for(int x : seq)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}