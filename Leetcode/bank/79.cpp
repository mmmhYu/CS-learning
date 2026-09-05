#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int len,row,col;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        len = word.size();
        row = board.size();
        col = board[0].size();
        visited = vector<vector<bool>> (row,vector<bool>(col,false));

        int index;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    index = 0;

                    if(DFS(board,index,word,i,j))
                        return true;
                    else{
                        visited[i][j] = false;
                    }
                }
            }
        }
        return false;
    }

    vector<int> my_search{-1,0,1,0,-1};
    

    bool DFS(vector<vector<char>>& board,int& index,string goal,int r,int c){
        index++;
        visited[r][c] = true;

        if(index == len)
            return true;

        int i;

        for(i = 0; i < 4; i++){
            int new_r = r + my_search[i],new_c = c + my_search[i+1];
            if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && (!visited[new_r][new_c]) && board[new_r][new_c] == goal[index]){
                if(DFS(board,index,goal,new_r,new_c)){
                    return true;
                }
                visited[new_r][new_c] = false;
                index--;
            }   
        }

        return false;

    }
};

int main(){
    vector<vector<char>> board{{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string word("AAB");
    Solution s;
    cout << s.exist(board,word) << endl;
    
    return 0;
}