#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i],1 + dp[i-j*j]);
            }
        }    
    
        return dp[n];
    }
};

int main() {
    Solution s;

    cout << s.numSquares(12) << endl; // 3 -> 4 + 4 + 4
    cout << s.numSquares(13) << endl; // 2 -> 4 + 9
    cout << s.numSquares(1) << endl;  // 1
    cout << s.numSquares(2) << endl;  // 2 -> 1 + 1
    cout << s.numSquares(43) << endl; // 3 -> 25 + 9 + 9

    return 0;
}

