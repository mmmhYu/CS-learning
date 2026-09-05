#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#define Max_Size 100
#define vextype string
#define arctype int

//邻接多重表
//这个方式会降低空间复杂度
typedef struct arcnode
{
    int i,j;
    struct arcnode *i_next,*j_next;
    arctype value;
}arcnode;

typedef struct vexnode
{
    vextype data;
    arcnode *next_arc;
}vexnode;

typedef struct AMLGraph
{
    vexnode list[Max_Size];
    int vexnum,arcnum;
}AMLGraph;