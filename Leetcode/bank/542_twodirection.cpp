#include<vector>
#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(),col = mat[0].size();

        vector<vector<int>> dp(row,vector<int>(col,100000));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!mat[i][j])
                        dp[i][j] = 0;
                else{
                    if(i > 0)
                        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                    if(j > 0)
                        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }

        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 0; j--){
                if(dp[i][j]){
                    if(i < row-1)
                        dp[i][j] = min(dp[i][j],dp[i+1][j]+1);
                    if(j < col-1)
                        dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                }
            }
        }

        return dp;
        
    }
};

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution s;

    // Test 1
    vector<vector<int>> mat1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Test 1:" << endl;
    printMatrix(s.updateMatrix(mat1));
    // Expected:
    // 0 0 0
    // 0 1 0
    // 0 0 0


    // Test 2
    vector<vector<int>> mat2 = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    cout << "Test 2:" << endl;
    printMatrix(s.updateMatrix(mat2));
    // Expected:
    // 0 0 0
    // 0 1 0
    // 1 2 1


    // Test 3：只有一个 0，检查多层 BFS
    vector<vector<int>> mat3 = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

    cout << "Test 3:" << endl;
    printMatrix(s.updateMatrix(mat3));
    // Expected:
    // 0 1 2 3
    // 1 2 3 4
    // 2 3 4 5
    // 3 4 5 6


    // Test 4：多个 0 从不同方向同时扩散
    vector<vector<int>> mat4 = {
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1}
    };

    cout << "Test 4:" << endl;
    printMatrix(s.updateMatrix(mat4));
    // Expected:
    // 0 1 2 1 0
    // 1 2 1 2 1
    // 2 1 0 1 2

    return 0;
}