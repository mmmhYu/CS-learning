#include<vector>
#include<iostream>
using namespace std;

#define min(a,b) a >= b ? b : a 
#define max(a,b) a >= b ? a : b 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n-1,max,tmp;

        max = tmp = min(l,r)*(r-l);

        while(l != r){
            l >= r ? r-- : l++;

            tmp = min(l,r)*(r-l);
            max =  max(tmp,max);
        }

        return max;
    }
};