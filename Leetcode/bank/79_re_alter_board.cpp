#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    int row,col,word_size;

    bool exist(vector<vector<char>>& board, string word){
        row = board.size();
        col = board[0].size();
        word_size = word.size();

        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                if(board[r][c] == word[0] && backtracking(board,word,1,r,c))
                        return true;
            }
        }

        return false;
        
    }

    vector<int> arr = {-1,0,1,0,-1};

    bool backtracking(vector<vector<char>>& board, string& word,int count, int r, int c){
        char ori = board[r][c];
        board[r][c] = '.';

        if(count == word_size)
            return true;

        for(int i = 0; i < 4; i++){
            int new_r = r + arr[i],new_c = c + arr[i+1];
            if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && board[new_r][new_c] == word[count] && backtracking(board,word,count+1,new_r,new_c))
                    return true;
        }

        board[r][c] = ori;
        return false;
    }
};