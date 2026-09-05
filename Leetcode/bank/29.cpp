#include<iostream>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int rest = abs(dividend),true_divisor = abs(divisor),n = 0;
        
        while(rest >= true_divisor){
            n++;
            rest -= true_divisor;
        }
        

    }
};