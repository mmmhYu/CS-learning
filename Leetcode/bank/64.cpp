#include<vector>
#include <iostream>
#include<algorithm>
#include<utility>

using namespace std;

class Solution {
public:
    int row,col;

    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        //vector<vector<int>> dp(row,vector<int>(col,0));

        for(int i = 1; i < col; i++)
            grid[0][i] += grid[0][i-1];

        for(int i = 1; i < row; i++)
            grid[i][0] += grid[i-1][0];
            
        for(int r = 1; r < row; r++){
            for(int c = 1; c < col; c++){
                grid[r][c] += min(grid[r-1][c],grid[r][c-1]);
            }
        }

        return grid[row-1][col-1];

    }
};

int main() {
    Solution s;

    // Test 1
    // Expected: 7
    vector<vector<int>> grid1 = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Test 1: " << s.minPathSum(grid1) << endl;


    // Test 2
    // Expected: 12
    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Test 2: " << s.minPathSum(grid2) << endl;


    // Test 3：只有一行
    // Expected: 10
    vector<vector<int>> grid3 = {
        {1, 2, 3, 4}
    };
    cout << "Test 3: " << s.minPathSum(grid3) << endl;


    // Test 4：只有一列
    // Expected: 10
    vector<vector<int>> grid4 = {
        {1},
        {2},
        {3},
        {4}
    };
    cout << "Test 4: " << s.minPathSum(grid4) << endl;


    // Test 5：路径选择比较明显
    // Expected: 7
    vector<vector<int>> grid5 = {
        {1, 1, 1},
        {9, 9, 1},
        {1, 1, 1},
        {1, 9, 1}
    };
    cout << "Test 5: " << s.minPathSum(grid5) << endl;

    return 0;
}