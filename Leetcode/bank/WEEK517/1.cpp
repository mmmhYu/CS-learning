#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> flag(101,-1);

        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            int tmp = nums[i];

            if(!flag[tmp])
                continue;    
            else if(flag[tmp] == -1){
                flag[tmp] = 1;
                cnt++;
                while(i < nums.size() && nums[i] == tmp)
                    i++;
                i--;
            }
            else{
                cnt--;
                flag[tmp] = 0;
            }
        }

        return cnt;
    }
};

int main(){
    vector<int> test = {1,2,2,1};
    Solution s;
    cout << s.countSpecialIntegers(test) << endl;

}