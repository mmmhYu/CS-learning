#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> v = grid[0];
        int n = v.size();
        
        for(vector<vector<int> >::iterator it=grid.begin(); it<grid.end(); it++){
            (*it).insert((*it).begin(),0);
            (*it).push_back(0);
        }
        
        vector<int> ins(n+2,0);
        grid.insert(grid.begin(),ins);
        grid.push_back(ins);
        
        int max=0,tmp;
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(grid[i][j] == 1){
                    tmp = 0;
                    dfs(grid,i,j,tmp);
                    max = max > tmp ? max : tmp;
                }
            }
        }
        return max;
    }

    void dfs(vector<vector<int>>& grid,int i,int j,int& area){
        if(grid[i][j] == 0)
            return;
        grid[i][j] = 0;

        area++;
        
        dfs(grid,i-1,j,area);
        dfs(grid,i+1,j,area);
        dfs(grid,i,j-1,area);
        dfs(grid,i,j+1,area);

    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;

}