#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int m,n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(),n = heights[0].size();
        vector<vector<int>> result,pacific(m,(vector<int> (n,0))),atlantic(m,(vector<int> (n,0)));
        
        for(int i = 0; i < n; i++){
            DFS(heights,0,i,pacific);
            DFS(heights,m-1,i,atlantic);
        }
        
        for(int i = 0; i < m; i++){
            DFS(heights,i,0,pacific);
            DFS(heights,i,n-1,atlantic);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)

            if(pacific[i][j] && atlantic[i][j])
                result.push_back(vector<int> {i,j});
        }

        return result;
    }

    vector<int> arr = {-1,0,1,0,-1};

    void DFS(const vector<vector<int>>& heights,int r,int c,vector<vector<int>>& condition){
        
        if(r < 0 || r >= m || c < 0 || c >= n)
            return;

        condition[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int new_r = r+arr[i],new_c = c+arr[i+1];

            if(new_r>=0 && new_r < m && new_c >= 0 && new_c < n 
                && heights[new_r][new_c] >= heights[r][c] && !condition[new_r][new_c])
            {
                DFS(heights,new_r,new_c,condition);
            }
        }
        
    }
};