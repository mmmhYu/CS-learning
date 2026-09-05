#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0,flag;

        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j <= i; j++){
                flag = 0;
                dfs(isConnected,i,j,cnt,flag);
            }
        }

        return cnt;
    }

    void dfs(vector<vector<int>>& Matrix,int r,int c,int& cnt,int &flag){
        if(r < 0 || r >= Matrix.size() || c < 0 || c > r || !Matrix[r][c])
            return;

        if(!flag){
            flag = 1;
            cnt++;
        }
        Matrix[r][c] = 0;

        for(int i = r; i < Matrix.size(); i++)
            dfs(Matrix,i,r,cnt,flag);

        for(int i = c; i < Matrix.size(); i++)
            dfs(Matrix,i,c,cnt,flag);

        for(int i = 0; i <= c; i++)
            dfs(Matrix,c,i,cnt,flag);

        for(int i = 0; i <= r; i++)
            dfs(Matrix,r,i,cnt,flag);
    }
};

int main(){
    vector<vector<int>> matrix = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    Solution s;
    cout << s.findCircleNum(matrix) << endl;

}