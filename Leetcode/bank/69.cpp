#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 1,r = x,mid;

        if(x < 1)
            return 0;

        while(l <= r){
            mid = l + (r-l)/2;

            if(mid*mid > x)
                r = mid-1;
            else if(mid*mid < x)
                l = mid+1;
            else
                return mid;

        }

        return r;

    }
};

int main() {
    Solution solution;

    int test[] = {
        0,
        1,
        2,
        3,
        4,
        8,
        9,
        15,
        16,
        24,
        25,
        26,
        100,
        2147395599,
        2147483647
    };

    int n = sizeof(test) / sizeof(test[0]);

    for (int i = 0; i < n; i++) {
        cout << "x = " << test[i]
             << ", sqrt = " << solution.mySqrt(test[i])
             << endl;
    }

    return 0;
}