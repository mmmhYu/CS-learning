#include<vector>
using namespace std;

class Solution {
public:
    int n;
    vector<bool> visited;

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        if(!n)
            return 0;
        
        int cnt = 0;
        visited = vector<bool> (n,false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                DFS(isConnected,i);
            }
        }

        return cnt;

    }

    void DFS(vector<vector<int>>& Matrix,int k){
        visited[k] = true;

        for(int i = 0; i < n; i++){
            if((!visited[i]) && Matrix[k][i])
                DFS(Matrix,i);
        }
    }
};