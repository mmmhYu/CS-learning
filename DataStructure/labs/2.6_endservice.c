#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

/*typedef struct Customer{
    int type,idx,sum;
}Customer;

typedef struct{
    int time,type;
}Event;*/

typedef struct CustNode{
    int arrtime,durtime,amount,next;
}CustNode;

//type:0-新顾客到达；1顾客离开
typedef struct{
    int time,type,custidx,next;
}EvtNode;

typedef struct{
    int front,rear;
}Queue;

typedef struct{
    int head,next;
}LinkList;

//全局变量
#define MAX 100
int Total,CloseTime,curtime;
Queue q[2];
int el;
CustNode cpool[MAX];
EvtNode epool[MAX];
int ctop = 0,etop = 0,sumtime = 0,cNum = 0;
//我的top=-1表示没有空闲

int emalloc(){
    if(etop == -1)
        return -1;

    int res = etop;
    etop = epool[res].next;

    epool[res].next = -1;
    return res;
}

void efree(int idx){
    if(idx < 0 || idx >= MAX)
        return;

    epool[idx].next = etop;
    etop = idx;
}

int cmalloc(){
    if(ctop == -1)
        return -1;

    int res = ctop;
    ctop = cpool[res].next;

    cpool[res].next = -1;
    return res;
}

void cfree(int idx){
    if(idx < 0 || idx >= MAX)
        return;

    cpool[idx].next = ctop;
    ctop = idx;
}

bool QueueEmpty(Queue q){
    return q.front == -1;
}

void EnQueue(Queue *q,int idx){
    cpool[idx].next = -1;

    if(QueueEmpty(*q))
        q->front = q->rear = idx;
    else{
        cpool[q->rear].next = idx;
        q->rear = idx;
    }
}

void DeQueue(Queue *q,int *idx){
    if(QueueEmpty(*q))
        return;

    int next = cpool[q->front].next;
    *idx = q->front;

    q->front = next;
    if(q->front == -1)
        q->rear = -1;
}

int GetHead(Queue q){
    return q.front;
}

int QueueLen(Queue q){
    int l = 0;
    int tmp = GetHead(q);
    while(tmp != -1){
        l++;
        tmp = cpool[tmp].next;
    }

    return l;
}

//--------------------------------------------------------
//以下为实验相关函数

bool MoreEvent(){
    return el != -1;
}

void InsertEvent(EvtNode evt){
    int index = emalloc();
    if(index == -1){
        printf("代办已达上限(事件池耗尽)");
        return;
    }

    epool[index] = evt;
    epool[index].next = -1;

    if(el == -1 || epool[el].time > evt.time){
        epool[index].next = el;
        el = index;
        return;
    }

    int idx = epool[el].next,pre = el;
    while(idx != -1){
        if(epool[idx].time < evt.time){
            pre = idx;
            idx = epool[idx].next;
        }
        else
            break;
    }

    epool[pre].next = index;
    epool[index].next = idx;
}

void GetEvent(EvtNode *evt){
    int idx = el;

    *evt = epool[idx];

    if(evt->time > CloseTime){
        evt->type = -1;//表示超过时间，不继续
        return;
    }

    curtime = evt->time;
    el = epool[idx].next;

    efree(idx);
}

int RandomAmount(){
    //100-5000
    int amount = (rand() % 50 + 1) * 100;

    //正-取，负-存
    if (rand() % 2 == 0)
        return -amount;

    return amount;
}

int RandomNewTime(){
    return rand() % 3 + 1;
}

int RandomServiceTime(){
    return rand() % 21 + 20;
}

void StartService(){
    while(!QueueEmpty(q[0])){
        int p;
        p = GetHead(*q);

        if(cpool[p].amount > Total){
            DeQueue(q,&p);
            EnQueue(q+1,p);
        }
        else{
            EvtNode finish;
            finish.time = curtime + cpool[p].durtime;
            finish.type = 1;
            finish.custidx = p;
            finish.next = -1;
            InsertEvent(finish);
            return;
        }
    }
}

void Arrive(EvtNode evt){
    int idx = cmalloc();
    if(idx == -1){
        printf("银行已满(用户池耗尽)\n");
        return;
    }

    cpool[idx].amount = RandomAmount();
    cpool[idx].arrtime = evt.time;
    cpool[idx].durtime = RandomServiceTime();
    
    //若当前没人且金额满足要求，需要启动服务链
    //只有遇到第一个满足要求的，才会开始，q[0]才会有人
    //同时q[0]非空也意味着队头的服务还没结束
    if(QueueEmpty(q[0])){
        if(Total >= cpool[idx].amount){
            EnQueue(&q[0],idx);
            EvtNode finish;
            finish.time = evt.time + cpool[idx].durtime;
            finish.type = 1;
            finish.custidx = idx;
            finish.next = -1;
            InsertEvent(finish);
        }
        else{
            EnQueue(q+1,idx);
        }
    }
    else
        EnQueue(q,idx);
    
    //下一个的到达事件
    EvtNode new;
    new.time = evt.time + RandomNewTime();
    
    if(new.time > CloseTime)
        return;

    new.type = 0;
    new.custidx = -1;
    new.next = -1;
    InsertEvent(new);
}

void FinishService(EvtNode evt){

    int custidx;
    DeQueue(q,&custidx);

    int amount = cpool[custidx].amount;
    int origin = Total;
    Total -= amount;
    sumtime += (evt.time - cpool[custidx].arrtime);
    cfree(custidx);
    cNum++;

    //检查队列二
    if(amount < 0){
        int l = QueueLen(q[1]);

        while(l > 0){
            int p;
            DeQueue(q+1,&p);
            l--;
            if(cpool[p].amount <= Total){
                sumtime += curtime - cpool[p].arrtime;
                Total -= cpool[p].amount;
                cfree(p);
                cNum++;
            }
            else
                EnQueue(q+1,p);

            if(Total <= origin)
                break;
        }
    }
    
    //找下一个服务事件
    if(!QueueEmpty(q[0]))
        StartService();

}

void CloseDay(){
    printf("今天工作(最后一个服务时间结束时刻)%d分钟,剩余总资金%d\n",curtime,Total);
    printf("今天营业%d分钟\n",CloseTime);
    printf("共%d位顾客结束服务，平均时长%.2f分钟\n",cNum,((float)sumtime/cNum)); 

    if(QueueEmpty(q[1]))
        printf("所有顾客均受到服务\n");
    else{
        printf("有%d位顾客没有被服务，等待时长:\n",QueueLen(q[1]));
        while (!QueueEmpty(q[1])){
            int p;
            DeQueue(q+1,&p);
            printf("(距离最后一次服务事件结束)已经等待%d分钟\n",curtime-cpool[p].arrtime);
            printf("(距离关门)已经等待%d分钟\n",CloseTime-cpool[p].arrtime);
        }
    }
}

void StartOperation(int money,int time){

    Total = money;
    CloseTime = time;

    ctop = 0;
    etop = 0;
    sumtime = 0;
    cNum = 0;
    curtime = 0;
    el = -1;

    for(int i = 0; i < 99; i++){
        cpool[i].next = i+1;
        epool[i].next = i+1;
    }
    cpool[99].next = epool[99].next = -1;

    q[0].front = q[0].rear = q[1].front = q[1].rear = -1;

    el = -1;

    EvtNode evt;
    evt.time = 0;
    evt.type = 0;
    InsertEvent(evt);
}

void BankSimulator(){
    int money = 10000,time = 600;
    StartOperation(money,time);

    while(MoreEvent()){
        EvtNode evt;
        GetEvent(&evt);

        int t = evt.type;

        if(t == -1)
            break;

        switch (t)
        {
        case 0:
            Arrive(evt);
            break;
        
        case 1:
            FinishService(evt);
            break;

        default:
            break;
        }
    }

    CloseDay();
}

int main(){
    srand((unsigned)time(NULL));
    BankSimulator();
}