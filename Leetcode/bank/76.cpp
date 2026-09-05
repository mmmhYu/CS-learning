#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0},win[128] = {0},sum = 0,tmp = 0,len = s.size();

        for(int i = 0; i < t.size(); i++){
            need[t[i]]++;
            sum++;
        }
            

        int l,r;
        l = r = 0;

        while(tmp != sum && r < len){
            int letter = s[r];

            if(need[letter]){
                if(win[letter] < need[letter])
                    tmp++;
                win[letter]++;
            }

            r++;
        }
        if(r==len && tmp < sum)
            return "";
        r--;

        int i = l,j = r,size = r-l+1,tmp_size;
        
        //调整i到会出问题的位置，并更新指标
        while(!need[s[i]] || need[s[i]] && need[s[i]]<win[s[i]]){
            if(need[s[i]] && need[s[i]]<win[s[i]]){
                win[i]--;
            }
            i++;
        }
        win[s[i]]--;

        l = i; r = j;
        size = j-i+1;

        while(j < len){
            //找到可以补回去的j
            do{
                j++;
                if(need[s[j]])
                    win[s[j]]++;
            }
            while(j<len && s[j]!=s[i]);

            //找到之后，调整窗口
            if(j<len){
                i++;
                while(!need[s[i]] || need[s[i]] && need[s[i]]<win[s[i]]){
                    if(need[s[i]] && need[s[i]]<win[s[i]]){
                        win[s[i]]--;
                    }
                    i++;
                }
                win[s[i]]--;
                tmp_size = j-i+1;

                if(tmp_size < size){
                    size = tmp_size;
                    l = i;r = j;
                }

            }
        }
        return s.substr(l,size);
    }
};

int main()
{
    Solution sol;

    string s[] = {
        "ADOBECODEBANC",
        "a",
        "aa",
        "ab",
        "cabwefgewcwaefgcf"
    };

    string t[] = {
        "ABC",
        "a",
        "aa",
        "b",
        "cae"
    };

    int n = sizeof(s) / sizeof(s[0]);

    for(int i = n-2; i < n-1; i++)
    {
        cout << "s: " << s[i] << endl;
        cout << "t: " << t[i] << endl;

        string ans = sol.minWindow(s[i], t[i]);

        cout << "ans: " << ans << endl;
        cout << "----------------" << endl;
    }

    return 0;
}