#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n,0);
        vector<vector<int>> graph(n);
        int Esize = edges.size();

        if(!Esize)
            return {0};

        for(int i = 0; i < Esize; i++){
            int u = edges[i][0],v = edges[i][1];

            deg[u]++;
            deg[v]++;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;

        for(int i = 0; i < n; i++)
            if(deg[i] == 1)
                q.push(i);

        int size = q.size(),last;
        int num = n;
        while(num > 2){
            num -= size;
            while(size){
                int index = q.front();
                q.pop();
                size--;

                deg[index]--;
                for(auto neibor:graph[index])
                    if(deg[neibor]){
                        deg[neibor]--;
                        if(deg[neibor] == 1)
                            q.push(neibor);
                    }
                        
            }

            size = q.size();

        }   

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
        
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