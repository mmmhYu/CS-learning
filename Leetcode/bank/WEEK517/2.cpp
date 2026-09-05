#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;

    long long my_pow(int m,int n){
        long long ans = 1;
        while(n){
            ans *= m;
            ans %= mod;
            n--;
        }
        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            int width = nums[i]%10,d = nums[i]/10;
            int cpy = d,digit = 0;
            while(cpy > 0){
                cpy /= 10;
                digit++;
            }
            int div = my_pow(10,digit-width),x = d/div,y = d%div;
            sum += my_pow(x,y);
        }

        return sum%(my_pow(10,9) + 7);
    }
};

int main(){
    Solution s;
    vector<long long> test = {59412};
    cout << s.sumDecoded(test) << endl;

}