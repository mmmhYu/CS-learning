#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#define Max_Size 100
#define vextype string
#define arctype int

//十字链表
//不会降低空间复杂度
typedef struct arcnode
{
    int head_vex,tail_vex;
    struct arcnode *head_link,*tail_link;
    arctype value;
}arcnode;

typedef struct vexnode
{
    vextype data;
    arcnode *first_in,*first_out;
}vexnode;

typedef struct OLGraph
{
    vexnode list[Max_Size];
    int arcnum,vexnum;
}OLGraph;

