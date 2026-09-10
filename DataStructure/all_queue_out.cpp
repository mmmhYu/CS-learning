#include<stack>
#include<vector>
#include<iostream>

using namespace std;

void dfs(const vector<int>& nums,
         int index,
         stack<int>& st,
         vector<int>& path,
         vector<vector<int>>& ans)
{
    if(!st.empty()){
        int tmp = st.top();
        path.push_back(tmp);
        st.pop();
        dfs(nums,index,st,path,ans);
        st.push(tmp);
        path.pop_back();
    }

    if(path.size() == nums.size()){
        ans.push_back(path);
        return;
    }

    if(index < nums.size()){
        st.push(nums[index]);
        dfs(nums,index+1,st,path,ans);
        st.pop();
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

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