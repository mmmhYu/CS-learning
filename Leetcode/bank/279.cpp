#include<iostream>
#include <cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);

        for(int i = 1; i <= sqrt(n); i++)
            dp[i*i] = 1;

        for(int k = 1; k <= n; k++){
            if(!(dp[k])){
                int m = k;
                for(int i = 1; i <= sqrt(k); i++)
                    m = min(m,dp[k-i*i]);

                dp[k] = m+1;
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

