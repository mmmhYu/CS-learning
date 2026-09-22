#include<string>
#include<stack>
#include<utility>
#include<iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(st.empty())
                    s[i] = 0;
                else
                    st.pop();
            }
        }

        while(!st.empty()){
            int idx = st.top();
            st.pop();
            s[idx] = 0;
        }

        string res;
        for(int i = 0; i < s.size(); i++)
            if(s[i])
                res.push_back(s[i]);

        return res;
    }
};

int main() {
    Solution s;

    // Test 1
    string s1 = "lee(t(c)o)de)";
    //cout << "Test 1: " << s.minRemoveToMakeValid(s1) << endl;
    // Expected: "lee(t(c)o)de"


    // Test 2
    string s2 = "a)b(c)d";
    //cout << "Test 2: " << s.minRemoveToMakeValid(s2) << endl;
    // Expected: "ab(c)d"


    // Test 3
    string s3 = "))((";
    //cout << "Test 3: " << s.minRemoveToMakeValid(s3) << endl;
    // Expected: ""


    // Test 4：已经合法
    string s4 = "(a(b)c)";
    //cout << "Test 4: " << s.minRemoveToMakeValid(s4) << endl;
    // Expected: "(a(b)c)"


    // Test 5：多余左括号
    string s5 = "a((b)c";
    //cout << "Test 5: " << s.minRemoveToMakeValid(s5) << endl;
    // Expected: "a(b)c" 或 "a(bc)"


    // Test 6：没有括号
    string s6 = "leetcode";
    //cout << "Test 6: " << s.minRemoveToMakeValid(s6) << endl;
    // Expected: "leetcode"


    // Test 7
    string s7 = ")))))";
    cout << "Test 7: " << s.minRemoveToMakeValid(s7) << endl;
    // 合法答案可能不唯一

    return 0;
}