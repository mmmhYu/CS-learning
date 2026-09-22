#include<vector>
#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) { 
        int row = matrix.size(),col = matrix[0].size(),max = 0;
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    int a = dp[i+1][j],b = dp[i][j+1],c = dp[i][j];
                    if((dp[i+1][j+1] = min({a,b,c})+1) > max)
                        max = dp[i+1][j+1];
                }
            }
        }
        return max*max;
    }
};

int main() {
    Solution s;

    // Test 1
    // Expected: 4
    vector<vector<char>> matrix1 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    cout << "Test 1: " << s.maximalSquare(matrix1) << endl;


    // Test 2：只有一个 1
    // Expected: 1
    vector<vector<char>> matrix2 = {
        {'0','1'},
        {'1','0'}
    };
    cout << "Test 2: " << s.maximalSquare(matrix2) << endl;


    // Test 3：全 0
    // Expected: 0
    vector<vector<char>> matrix3 = {
        {'0','0'},
        {'0','0'}
    };
    cout << "Test 3: " << s.maximalSquare(matrix3) << endl;


    // Test 4：3×3 全 1
    // Expected: 9
    vector<vector<char>> matrix4 = {
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    };
    cout << "Test 4: " << s.maximalSquare(matrix4) << endl;


    // Test 5：只有一行
    // Expected: 1
    vector<vector<char>> matrix5 = {
        {'1','1','1','1'}
    };
    cout << "Test 5: " << s.maximalSquare(matrix5) << endl;

    return 0;
}