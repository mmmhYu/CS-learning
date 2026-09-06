#include<vector>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<int> need(26,0),cur(26,0),have(26,0);
        vector<vector<int>> all_Wordhash;
        vector<bool> visited(wordList.size(),false);
        queue<string> q;

        for(auto c:beginWord)
            cur[c - 'a']++;

        for(auto word:wordList){
            have = vector<int> (26,0);

            for(auto c:word)
                have[c - 'a']++;

            all_Wordhash.push_back(have);
        }

        for(auto c:endWord)
            need[c - 'a']++;

        q.push(beginWord);

        int q_size = 1;

        while(!q.empty()){
            q_size = q.size();
            while(q_size){
                
            }
        }
    }
};
