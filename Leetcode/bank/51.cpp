#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
public:
    vector<bool> can_col,diag1,diag2;

    vector<vector<string>> solveNQueens(int n) {
        if(n == 1)
            return vector<vector<string>> (1,{"Q"});

        can_col = vector<bool>(n,true);
        diag1 = vector<bool>(2*n-1,true);
        diag2 = vector<bool>(2*n-1,true);
        
        vector<vector<string>> res;
        vector<string> board(n,string(n,'.'));
        int cnt = 0;

        for(int i = 0; i < n; i++)
            backTracking(board,res,cnt,n,0,i);

        return res;
    }

    void backTracking(vector<string>& board,vector<vector<string>>& res,int& cnt,int n,int r,int c){
        int d1 = c-r+n-1,d2 = c+r;

        if(can_col[c] && diag1[d1] && diag2[d2]){
            cnt++;
            board[r][c] = 'Q';
            if(cnt == n){
                res.push_back(board);
                board[r][c] = '.';
                cnt--;
                return;
            }
            
            can_col[c] = diag1[d1] = diag2[d2] = false;
        }
        else
            return;

        for(int i = 0; i < n; i++)
            backTracking(board,res,cnt,n,r+1,i);

        board[r][c] = '.';
        cnt--;
        can_col[c] = diag1[d1] = diag2[d2] = true;
        return;

    }
};

int main() {
    Solution s;

    int n = 5;
    vector<vector<string>> res = s.solveNQueens(n);

    for (const auto& board : res) {
        for (const string& row : board)
            cout << row << '\n';

        cout << "----" << '\n';
    }

    return 0;
}