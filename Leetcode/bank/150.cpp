#include<string>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool Is_OP(string str){
        if(str.size() > 1)
            return false;

        return str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/';
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> calc(128,0);
        calc['+'] = 0;
        calc['-'] = 1;
        calc['*'] = 2;
        calc['/'] = 3;

        stack<int> OPND;
        
        for(int i = 0; i < tokens.size(); i++){
            string str = tokens[i];
            if(Is_OP(str)){
                int x,y;
                y = OPND.top();
                OPND.pop();
                x = OPND.top();
                OPND.pop();
                switch (calc[str[0]])
                {
                case 0:
                    OPND.push(x + y);
                    break;
                case 1:
                    OPND.push(x - y);
                    break;
                case 2:
                    OPND.push(x * y);
                    break;
                case 3:
                    OPND.push(x / y);
                    break;
                default:
                    break;
                }
            }
            else
                OPND.push(stoi(str));
        }

        return OPND.top();
        
    }
};

int main() {
    Solution s;

    // Test 1
    // (2 + 1) * 3 = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    //cout << "Test 1: " << s.evalRPN(tokens1) << endl;
    // Expected: 9


    // Test 2
    // 4 + (13 / 5) = 6
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    //cout << "Test 2: " << s.evalRPN(tokens2) << endl;
    // Expected: 6


    // Test 3
    vector<string> tokens3 = {
        "10", "6", "9", "3", "+", "-11", "*",
        "/", "*", "17", "+", "5", "+"
    };
    cout << "Test 3: " << s.evalRPN(tokens3) << endl;
    // Expected: 22


    // Test 4：检查减法顺序
    vector<string> tokens4 = {"8", "3", "-"};
    cout << "Test 4: " << s.evalRPN(tokens4) << endl;
    // Expected: 5


    // Test 5：检查除法顺序
    vector<string> tokens5 = {"12", "3", "/"};
    cout << "Test 5: " << s.evalRPN(tokens5) << endl;
    // Expected: 4


    // Test 6：负数
    vector<string> tokens6 = {"-4", "2", "/"};
    cout << "Test 6: " << s.evalRPN(tokens6) << endl;
    // Expected: -2

    return 0;
}