#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {

        if(s.size() == 1)
            return !!(s[0] - '0');

        vector<int> dp(s.size(),0);
            
        dp[0] = !!(s[0]-'0');
        int tmp = (s[0]-'0')*10 + (s[1]-'0');
        dp[1] = dp[0]*(!!(s[1]-'0')) + (tmp > 9 && tmp <= 26);

        for(int i = 2; i < s.size(); i++){
            int tmp = (s[i-1]-'0')*10 + (s[i]-'0');
            bool isanother = tmp > 9 && tmp <= 26;
            dp[i] = dp[i-1]*(!!(s[i]-'0')) + dp[i-2]*isanother ;
        }

        return dp[s.size()-1];
    }
};

int main() {
    Solution sol;

    //cout << sol.numDecodings("12") << endl;    // 2
    //cout << sol.numDecodings("226") << endl;   // 3
    cout << sol.numDecodings("06") << endl;    // 0
    //cout << sol.numDecodings("10") << endl;    // 1
    //cout << sol.numDecodings("2101") << endl;  // 1
    //cout << sol.numDecodings("11106") << endl; // 2
    //cout << sol.numDecodings("27") << endl;    // 1
    //cout << sol.numDecodings("100") << endl;   // 0
    //cout << sol.numDecodings("111") << endl;   // 3
    //cout << sol.numDecodings("1") << endl;     // 1
    //cout << sol.numDecodings("0") << endl;     // 0

    return 0;
}