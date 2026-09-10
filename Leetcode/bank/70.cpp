#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n){
        vector<int> dp(2);

        if(n == 1)
            return 1;

        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
            dp[i%2] = dp[i%2] + dp[(i+1) % 2];

        return dp[(n+1) % 2];
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(5) << endl;

}