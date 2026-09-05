#include<vector>
using namespace std;

class Solution {
public:
    int row,col;
    vector<vector<bool>> pacific,atlantic;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        vector<vector<int>> ans;

        pacific = vector<vector<bool>> (row,vector<bool>(col,false));
        pacific = vector<vector<bool>> (row,vector<bool>(col,false));

        for(int r = 0; r < row; r++){
            can_arrive(heights,pacific,r,0);
            can_arrive(heights,atlantic,r,col-1);
        }

        for(int c = 0; c < col; c++){
            can_arrive(heights,pacific,0,c);
            can_arrive(heights,atlantic,row-1,c);
        }
    
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(pacific[r][c] && atlantic[r][c])
                    ans.push_back({r,c});
            }
        }

        return ans;
        
    }

    vector<int> move={-1,0,1,0,-1};

    void can_arrive(vector<vector<int>>& heights,vector<vector<bool>> condition,int r,int c){
        condition[r][c] = 1;

        for(int i = 0; i < 4; i++){
            int new_r = r + move[i],new_c = c + move[i+1];

            if(new_r >= 0 && new_r < row && new_c >=0 && new_c < col && heights[new_r][new_c] >= heights[r][c])
                can_arrive(heights,condition,new_r,new_c);

        }
    }


};