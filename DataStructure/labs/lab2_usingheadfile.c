#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int enter_time,duration;
}Customer;


typedef struct{
    int occur_time,event_type;//event_type:0-Departure; [1,qNum]-Arrival&Counter
}Event;

#define qtype Customer
#define ltype Event
#define EvtNode LNode

#include"../homework/SqQueue.h"
#include"../homework/LinkList.h"

#define qNum 3
#define MAXQSIZE 100
#define MAX_TIME 200

#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

/*typedef struct EventNode{
    Event evt;
    struct EventNode *next;
}EventNode,*EventList;

#define LinkList EventList

//循环队列，牺牲一个位置实现
typedef struct{
    Customer *base;
    int front,rear;
}CustomerQueue,*Counter;

#define SqQueue CustomerQueue*/

//全局变量
LinkList EventList;
SqQueue* Counters;
int cNum = 0;
int OpenTime = 3600;

void OpenForDay(){
    printf("--------开始营业--------");

    //初始化队列和链表
    Counters = (SqQueue*)malloc((qNum+1) * sizeof(SqQueue));
    for(int i = 1; i < 4; i++){
        SqQueue cq = Counters[i];
        cq.base = (Customer*)malloc(sizeof(Customer));
        cq.front = cq.rear = 0;
    }

    EventList = (LNode*)malloc(sizeof(LNode));
    EventList->next = NULL;
}

Status MoreEvent(){
    return EventList->next;
}

//将第一个事件从链表中拿出来
Status GetEvent(Event *evt){
    *evt = EventList->next->val;
    EventList->next = EventList->next->next;
    return OK;
}

int ShortestLength(){
    int min = 1;

    for(int i = 2; i <= qNum; i++){
        if(QueueLenth(Counters[i]) < QueueLenth(Counters[min]))
            min = i;
    }

    return min;
}

//按时间顺序插入事件
//如果进入的时间超过营业时间，不会插入；但如果是离开时间超过，允许插入
Status EventInsert(Event evt){
    if(evt.event_type && evt.occur_time > OpenTime)
        return ERROR;

    EvtNode *eNode = (EvtNode*)malloc(sizeof(EvtNode));
    eNode->val = evt;

    EvtNode *p = EventList->next, *pre = EventList;
    while(p && p->val.occur_time <= evt.occur_time){
        pre = p;
        p = p->next;
    }
    
    eNode->next = p; 
    pre->next = eNode;
    
    return OK;
}

//处理这个顾客排到哪，如果是第一个还要计算departure
//处理之后，计算下一个Arrival Time，插入事件链表
void CustomerArrival(int time,int type){
    Customer c;
    int duration = rand() % 61 + 60;
    c.duration = duration;
    c.enter_time = time;

    if(QueueEmpty(Counters[type])){
        int Depart_time = time + c.duration;
        Event evt;
        evt.event_type = 0;
        evt.occur_time = Depart_time;
        EventInsert(evt);
    }

    EnQueue(&Counters[type],c);

    //计算下一个进入事件的时间

}

//处理离开，下一个顾客到队头，计算离开时间加入事件列表
CustomerDeparture(){

}

void CloseForDay(){

}

void BankSimulation(int CloseTime){
    OpenForDay();

    while(moreEvent()){
        Event evt;
        GetEvent(&evt);
        int etype = evt.event_type;
        switch (!etype){
        case 0:
            CustomerArrival(evt.occur_time,evt.event_type);
            break;

        case 1:
            CustomerDeparture();
            break;

        default:
            break;
        }
    }

    CloseForDay();

}