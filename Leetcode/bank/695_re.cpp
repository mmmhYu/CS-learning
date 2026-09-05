#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int row,col;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;

        row = grid.size();
        col = grid[0].size();

        int max_area = 0,tmp_area;

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(grid[r][c])
                    tmp_area = DFS(grid,r,c);
                    
                max_area = tmp_area > max_area ? tmp_area : max_area;

            }
        }

        return max_area;
    }

    vector<int> search{-1,0,1,0,-1};

    int DFS(vector<vector<int>>& Matrix,int r,int c){
        Matrix[r][c] = 0;
        int area = 1;

        for(int i = 0; i < 4; i++){
            int new_r = r+search[i],new_c = c+search[i+1];
            if(new_r >= 0 && new_r < row && new_c >=0 && new_c < col && Matrix[new_r][new_c])
                area += DFS(Matrix,new_r,new_c);
        }
        return area;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
}