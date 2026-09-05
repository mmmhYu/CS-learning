#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

#define Max_Size 100
#define vextype string
#define arctype int

//邻接表法
//边/弧链表
typedef struct arcnode
{
    int index,len;
    struct arcnode* next;
}arcnode;

//顶点结点，包括数据域、指针域
typedef struct vexnode
{
    vextype data;
    int index;
    arcnode *first_arc;
}vexnode,AdjList[Max_Size];

//图
typedef struct ALGraph
{
    vexnode arr[Max_Size];
  //AdjList arr;也可以
    int vexnum,arcnum;
}ALGraph;

vector<bool> visited(Max_Size,false);

queue<int> q;

void visit(vexnode v){
    visited[v.index] = true;
    cout << v.data << endl;
}

void BFS(ALGraph G,int v){
    visit(G.arr[v]);
    visited[v] = 1;

    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(arcnode *p = G.arr[u].first_arc; p; p = p->next){
            if(!visited[p->index]){
                visit(G.arr[p->index]);
                q.push(p->index);
            }
        }
    }
}

void DFS(const ALGraph& G,int v){
    //visited[v] = true;
    visit(G.arr[v]);
    
    arcnode *p = G.arr[v].first_arc;
    while(p){

        if(!visited[p->index])
            DFS(G,p->index);

        p = p->next;
    }    
}

vector<int> dist(Max_Size);
vector<int> path(Max_Size);

void short_route_BFS(ALGraph& G, int v){
    for(int i = 0; i < Max_Size; i++){
        dist[i] = 65535;
        path[i] = -1;
    }

    dist[v] = 0;
    path[v] = v;
    visited[v] = 1;
    
    q.push(v);

    int u,w;
    while(!q.empty()){
        u = q.front();
        q.pop();

        for(arcnode *p = G.arr[u].first_arc; p; p = p->next){
            w = p->index;
            if(!visited[w]){
                visited[w] = 1;
                q.push(w);
                path[w] = u;
                dist[w] = dist[u] + 1;
            }
        }
    }
}

//Dijkstra
#define infinity 66666
vector<bool> shortroute_visited(Max_Size,false);
vector<int> dis(Max_Size,infinity);
vector<int> path(Max_Size,-1);
ALGraph g;

//找到dis数组最小值，返回下标的函数，注意返回不能是已经visit的
int find_min(vector<int> arr){
    int index = -1;
    int min = infinity;
    for(int i = 0; i < Max_Size; i++){
        if((!shortroute_visited[i]) && dis[i] < min){
            index = i;
            min = dis[i];
        }       
    }

    return index;
}

void djstra(int start){
    dis[start] = 0;
    shortroute_visited[start] = true;

    int index;

    while((index = find_min(dis)) != -1){
        shortroute_visited[index] = true;
        int cur_len = dis[index];
        arcnode *p = g.arr[index].first_arc;
        while(p){
            if(cur_len + p->len < dis[p->index]){
                dis[p->index] = cur_len + p->len;
                path[p->index] = index;
            }
        p = p->next;
        }
    }
}


int size = g.vexnum;
vector

void Floyd(){

}
