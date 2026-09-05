#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int n;
    vector<int> arr = {-1,0,1,0,-1};

    int shortestBridge(vector<vector<int>>& grid){
        int cnt = 0;
        queue<pair<int,int>> BFS_queue;
        n = grid.size();

        int flag = 0;

        for(int r = 0; r < n && !flag; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1){
                    DFS(grid,BFS_queue,r,c);
                    flag = 1;   
                    break;
                }
            }
        }

        while(!BFS_queue.empty()){
            int size = BFS_queue.size();
            while(size > 0){
                auto [cur_r,cur_c] = BFS_queue.front();
                BFS_queue.pop();
                size--;

                for(int i = 0; i < 4; i++){
                    int new_r = cur_r + arr[i],new_c = cur_c + arr[i+1];
                    if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n){
                        int& cur = grid[new_r][new_c];
                        if(!cur){
                            cur = 2;
                            BFS_queue.push({new_r,new_c});
                        }
                        else if(cur == 2)
                            continue;
                        else
                            return cnt;
                    } 
                }
            }
            cnt++;

        }

        return -1;
    }

    void DFS(vector<vector<int>>& grid,queue<pair<int,int>>& BFS_queue,int r,int c){
        grid[r][c] = 2;
        BFS_queue.push({r,c});

        for(int i = 0; i < 4; i++){
            int new_r = r + arr[i],new_c = c + arr[i+1];

            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && grid[new_r][new_c] == 1)
                DFS(grid,BFS_queue,new_r,new_c);

        }
    }

};

int main() {
    Solution s;

    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    cout << s.shortestBridge(grid) << endl;

    return 0;
}