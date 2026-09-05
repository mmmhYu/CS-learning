#include<vector>
using namespace std;

class Solution {
public:
    int row,col;

    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        for(int c = 0; c < col; c++){
            if(board[0][c] == 'O')
                DFS(board,0,c);

            if(board[row-1][c] == 'O')    
                DFS(board,row-1,c);
        }

        for(int r = 1; r < row-1; r++){
            if(board[r][0] == 'O')
                DFS(board,r,0);

            if(board[r][col-1] == 'O')    
                DFS(board,r,col-1);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'x')
                    board[i][j] = 'O';
            }
        }
    }

    vector<int> search{-1,0,1,0,-1};

    void DFS(vector<vector<char>>& board,int r,int c){

        board[r][c] = 'x';

        for(int i = 0; i < 4; i++){
            int cur_r = r + search[i],cur_c = c + search[i+1];
            if(cur_r >= 0 && cur_r < row && cur_c >= 0 && cur_c < col && board[cur_r][cur_c] == 'O')
                DFS(board,cur_r,cur_c);
        }
        
    }
};