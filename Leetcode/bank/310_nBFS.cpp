#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        unsigned height = n,tmp;
        vector<int> res;

        for(int i = 0; i < n; i++){
            tmp = BFS(n,i,edges);

            if(tmp < height){
                height = tmp;
                res = vector<int>(0);
                res.push_back(i);
            }
            else if(tmp == height)
                res.push_back(i);
        }

        return res;
    }

    unsigned BFS(int n,int index,vector<vector<int>>& edges){
        queue<int> q;
        q.push(index);

        int Esize = edges.size();

        vector<bool> visited(Esize,false);

        unsigned size = 1,height = 0;

        while(!q.empty()){
            height++;
            size = q.size();

            while(size){
                int cur = q.front();
                q.pop();
                size--;

                for(int i = 0; i < Esize; i++){
                    if(visited[i])
                        continue;
                    else{
                        if(edges[i][0] == cur){
                            q.push(edges[i][1]);
                            visited[i] = true;
                        }
                        else if(edges[i][1] == cur){
                            q.push(edges[i][0]);
                            visited[i] = true;
                        }
                    }
                }

            }
        }

        return height;
    }
};

void print(const vector<int>& ans) {
    for (int x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    Solution s;

    // 例1：单中心
    // 答案：[1]
    int n1 = 4;
    vector<vector<int>> edges1 = {
        {1, 0},
        {1, 2},
        {1, 3}
    };
    print(s.findMinHeightTrees(n1, edges1));


    // 例2：双中心
    // 0 - 1 - 2 - 3 - 4 - 5
    // 答案：[2, 3]
    int n2 = 6;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5}
    };
    print(s.findMinHeightTrees(n2, edges2));


    // 例3：复杂一些，单中心
    // 答案：[2]
    int n3 = 9;
    vector<vector<int>> edges3 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {2, 5},
        {5, 6},
        {2, 7},
        {7, 8}
    };
    print(s.findMinHeightTrees(n3, edges3));


    // 例4：复杂一些，双中心
    // 答案：[3, 4]
    int n4 = 7;
    vector<vector<int>> edges4 = {
        {0, 3},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5},
        {4, 6}
    };
    print(s.findMinHeightTrees(n4, edges4));


    // 例5：只有一个节点
    // 答案：[0]
    int n5 = 1;
    vector<vector<int>> edges5 = {};
    print(s.findMinHeightTrees(n5, edges5));

    return 0;
}