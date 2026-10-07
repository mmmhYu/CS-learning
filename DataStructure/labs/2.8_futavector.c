#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//一个时间列表，里面同时最多只有一个电梯事件
//电梯每次要么停在一个地方，不断询问是否关门
//要么运动一层，便于及时修改目标楼层，而且也与现实一致：到一层的运动一旦开始就不会终止
//每次按电钮，都会调用call函数，判断是否更改目标
//到达一层之后，根据目标，判断下一个一层或者停下之类的
//总之就是利用passenger的动作，耦合call，call的结果耦合control，control就是用来调度电梯的
//control会在每次电梯事件结束调用(?)

typedef enum {
    EV_NEW,
    EV_LEAVE,
    EV_GETOFF,
    EV_ENTER,

    EV_GOUP,
    EV_GODOWN,
    EV_ARRIVE,
    EV_DOOROPEN,
    EV_DOORCLOSE,
    EV_TEST,
    EV_TRANSFER

} EventType;

typedef struct {
    int time;
    EventType type;
    int floor;
    int direction;
    int idx;
}Event;

typedef struct ENode{
    Event evt;
    struct ENode *next;
}ENode,*EventList;

typedef struct{
    int Infloor,Outfloor,ArrivalTime,GiveUpTime,idx;
}Passenger;

#define qtype Passenger
#define stype Passenger
#include"../homework/SqQueue.h"
#include"../homework/SqStack_ppt.h"

#define FLOOR_COUNT 5
#define DIR_DOWN 0
#define DIR_UP 1

//State:-1-GoDown; 0-Idle; 1-GoUp
typedef struct{
    int Floor,D1,D2,D3,State,Target,Capability;
    int LastTransTime,CloseTime;
    bool CallUp[5],CallDown[5],CallCar[5];
    SqStack Passengers[5];
}Elevator;

//全局变量
int Tolerence = 120,Idle_Time = 300,Test_Time = 40,
    Travel_Time = 50,Brake_Time = 15,Accelerate_Time = 15,
    Door_Time = 20,Enter_Time = 25,Out_Time = 20,PNum = 0,Time = 0;
Elevator E;
EventList el;
//第一维表示楼层，第二维表示方向：0向下，1向上
SqQueue CustQueue[FLOOR_COUNT][2];

void StartOperation(){
    printf("--------电梯开始运行--------");

    //初始化电梯
    for(int i = 0; i < 5; i++)
        E.CallCar[i] = E.CallDown[i] = E.CallUp[i] = 0;
    E.D1 = E.D2 = E.D3 = 0;
    E.Floor = 1;
    E.State = 0;
    E.Target = -1;
    //先默认不会出现满载情况
    E.Capability = 10000;
    for(int i = 0; i < 5; i++){
        E.Passengers[i].base = (stype*)malloc(E.Capability*sizeof(stype));//初始化乘客栈
        E.Passengers[i].top = E.Passengers[i].base;
        E.Passengers[i].size = E.Capability;
    }

    //初始化事件列表
    el = (EventList)malloc(sizeof(ENode));
    Event evt;
    evt.time = 0;
    evt.type = EV_NEW;
    ENode *en = (ENode*)malloc(sizeof(ENode));
    en->evt = evt;
    en->next = NULL;
    el->next = en;

    //初始化每层的向下、向上候梯队列
    for(int floor = 0; floor < FLOOR_COUNT; floor++)
        for(int direction = DIR_DOWN; direction <= DIR_UP; direction++)
            InitQueue(&CustQueue[floor][direction]);
}

bool MoreEvent(){
    return el->next;
}

//取出并删除第一个事件
void GetEvent(Event *evt){
    //更新全局时间
    Time = evt->time;

    *evt = el->next->evt;
    ENode *node = el->next->next;
    free(el->next);
    el->next = node;
}

//随机生成乘客
void GenPassenger(Passenger *p,int time){
    p->Infloor = rand() % 5;
    do{
        p->Outfloor = rand() % 5;
    }while(p->Outfloor == p->Infloor);

    p->ArrivalTime = time;
    p->GiveUpTime = time + Tolerence;
    p->idx = ++PNum;

    printf("第%d个乘客来到第%d层,想要到达第%d层",p->idx,p->Infloor,p->Outfloor);
    
    //增加离开事件或者在其他函数中直接进入电梯(不设置离开事件)，取决于电梯的状况
    if(E.Floor != p->Infloor){
        Event Leave;
        Leave.floor = p->Infloor;
        Leave.time = p->GiveUpTime;
        Leave.type = EV_LEAVE;
        Leave.direction = p->Outfloor > p->Infloor ? 1 : -1;
        //为了离开事件取出来的时候可以确定是从哪个队列里面拿
        EventInsert(Leave);
    }//离开事件会一直存在，直到这个事件被取出，或者随对应的电梯到达而被删除

}

//按照时间顺序插入事件
void EventInsert(Event evt){
    ENode *e = (ENode*)malloc(sizeof(ENode));
    e->evt = evt;
    
    ENode *cur = el->next,*pre = el;
    while(cur && cur->evt.time <= evt.time){
        pre = cur;
        cur = cur->next;
    }
    pre->next = e;
    e->next = cur;
}

//每次按下电钮，都会让elevator判断是否更新目标，是否更新事件
void CallElevator(int time){
    int minup,mindown;
    for(minup = E.Floor; minup < 5; minup++)
        if(E.CallUp[minup] || E.CallDown[minup] || E.CallCar[minup])
            break;

    for(mindown = E.Floor; mindown >= 0; mindown--)
        if(E.CallUp[mindown] || E.CallDown[mindown] || E.CallCar[mindown])
            break;

    //向上的最小，如果没有向上的，那就是为-1，表示只有向下的需求
    minup = minup == 5 ? -1 : minup;
    //最小的向下，由于-1已经代表了没有向下的楼层，所以就不用管了
    //mindown = mindown == -1 ? -1 : mindown;

    //向上
    if(E.State == 1){
        //但是没有向上的需求
        if(minup == -1){
            //还同时没有向下的需求
            if(mindown == -1){
                E.State = 0;
                E.Target = -1;
            }
            //有向下的需求
            else{
                E.State = -1;
                E.Target = mindown;
            }
        }
        //还有向上的需求
        else
            E.Target = minup;
    }
    //向下，类似
    else if(E.State == -1){
        if(mindown == -1){
            if(minup == -1){
                E.State = 0;
                E.Target = -1;
            }
            else{
                E.State = 1;
                E.Target = minup;
            }
        }
        else
            E.Target = mindown;        
    }
    //Idle，注意需要调用control
    else{
        if(mindown == -1 && minup == -1)
            E.Target = -1;
        else if(mindown == -1){
            E.Target = minup;
            E.State = 1;
        }
        else if(minup == -1){
            E.Target = mindown;
            E.State = -1;
        }
        else{
            int up = minup-E.Floor,down = E.Floor - mindown;
            if(up < down){
                E.State = 1;
                E.Target = minup;
            }
            else{
                E.State = -1;
                E.Target = mindown;
            }
        }
    Controller(time);
    }
}

//NEW事件：生成一个乘客，同时生成下一个乘客进入(生成)的时刻(下一个NEW事件)
void psgNew(Event evt){
    Passenger p;
    GenPassenger(&p,evt.time);

    int direction = p.Outfloor > p.Infloor ? DIR_UP : DIR_DOWN;
    bool isNewCall = direction == DIR_UP
        ? !E.CallUp[p.Infloor]
        : !E.CallDown[p.Infloor];

    //每名乘客只进入一次对应楼层、对应方向的候梯队列
    EnQueue(&CustQueue[p.Infloor][direction],p);

    if(isNewCall){
        if(direction == DIR_UP)
            E.CallUp[p.Infloor] = 1;
        else
            E.CallDown[p.Infloor] = 1;

        CallElevator(evt.time);
    }
    
    //还要新增一个NEW
    int time =evt.time + rand() % 81 + 20;
    Event new_evt;
    new_evt.time = time;
    new_evt.type = EV_NEW;
    EventInsert(new_evt);
}

//LEAVE事件：离开，在队列中删除该名乘客（也是这一层这个方向队头元素）
void psgLeave(Event evt){
    Passenger leaveP;
    int f = evt.floor,d = evt.direction;
    int queueDirection = d == 1 ? DIR_UP : DIR_DOWN;

    //这里默认每个乘客的忍耐时间是相等的，所以先入队的，一定会是第一个想离开的
    //但是如果是随机生成的tolerance，需要修改算法
    if(DeQueue(&CustQueue[f][queueDirection],&leaveP) != OK){
        printf("错误：LEAVE没有找到对应乘客\n");
        return;
    }
    
    printf("%d时刻:第%d个乘客离开了,他想从第%d层到达第%d层",
            leaveP.GiveUpTime,leaveP.idx,leaveP.Infloor,leaveP.Outfloor);
}

//电梯控制函数
void Controller(int time){
    //没有新的目标
    if (E.Target == -1) {
        E.State = 0;
        return;
    }

        Event new_evt;

    if (E.Floor == E.Target) {
        //Idle说明原本就在这一层，不需要减速
        //非Idle说明刚刚运行到这里，需要15t减速
        int brakeTime = E.State == 0 ? 0 : Brake_Time;

        new_evt.time = time + brakeTime + Door_Time;

        new_evt.type = EV_DOOROPEN;
        EventInsert(new_evt);

        return;
    }

    //当前层不是目标层，安排移动一层
    int direction = E.Target > E.Floor ? 1 : -1;

    E.State = direction;

    new_evt.time = time + Travel_Time;
    new_evt.type = EV_ARRIVE;
    new_evt.direction = direction;
    new_evt.floor = E.Floor + direction;

    EventInsert(new_evt);
}

//开门事件
void elevatorOpen(Event evt){
    printf("%d时刻:电梯在第%d层开门",evt.time,evt.floor);
    SqStack *PassengerStack = &E.Passengers[evt.floor];

    int time = evt.time;
    //默认先下后上
    //这里一次性只插入一个下电梯事件，在下电梯函数里面有更详细的判断
    //是为了处理一边上下，一边有新乘客产生的复杂情况
    if(!StackEmpty(*PassengerStack)){
        time += Out_Time;
        Passenger psg;
        psg = GetTop(*PassengerStack);
        Event GetOff;
        GetOff.idx = psg.idx;
        GetOff.time = time;
        GetOff.type = EV_GETOFF;
        EventInsert(GetOff);
    }
    //没人下，直接启动上电梯链
    else{
        //当然还是需要判断到达的时候，这一层还有没有人
        if(E.State == -1){
            if(!QueueEmpty(CustQueue[E.Floor][DIR_DOWN])){
                time += Enter_Time;
                Passenger psg;
                psg = CustQueue[E.Floor][DIR_DOWN].base[CustQueue[E.Floor][DIR_DOWN].front];
                Event Enter;
                Enter.idx = psg.idx;
                Enter.time = time;
                Enter.type = EV_ENTER;
                EventInsert(Enter);
            }
            else{
            //这里我的想法是，通过设置E的参数，在新的乘客到达事件判断中，加入一个对于时间的判断
            //就是说到达事件比他早，那就美美进入，插入进入事件
            //否则一起归为离开事件

            }
        }
    }

}

void ElevatorSimulation(){
    StartOperation();

    while(MoreEvent()){
        Event evt;
        GetEvent(&evt);

        EventType t = evt.type;
        switch (t)
        {
        case EV_NEW:
            psgNew(evt);
            break;
        
        case EV_LEAVE:
            psgLeave(evt);
            break;

        case EV_DOOROPEN:
            elevatorOpen(evt);
            break;

        case EV_ARRIVE:
            

        default:
            printf("No Such Event!");
            break;
        }

    }

}
