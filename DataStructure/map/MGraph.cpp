#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;

#define Max_Size 100
#define vextype string
#define arctype int

//邻接矩阵法，一维数组存储数据，二维数组存储边/弧
typedef struct MGraph
{
    vextype vex[Max_Size];
    arctype arc[Max_Size][Max_Size];
    int vexnum,arcnum;
}MGraph;