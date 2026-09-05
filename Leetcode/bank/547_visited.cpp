#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0,n = isConnected.size();
        vector<bool> visited(n,false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                cnt++;
            }
        }

        return cnt;
    }

    void dfs(vector<vector<int>>& Matrix,int i,vector<bool>& visited){

        visited[i] = true;

        for(int r = 0; r < Matrix.size(); r++){
            if(Matrix[i][r]){
                Matrix[r][i] = Matrix[i][r] = 0;
                if(!visited[r])
                    dfs(Matrix,r,visited);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    Solution s;
    cout << s.findCircleNum(matrix) << endl;

}