
//"MMCCCXCIX"

#include<stdio.h>
int romanToInt(char* s) {
    int count[7]={0},sum=0,i,temp=0;
    char *p;
    p=s;
    while(*s!=0){
        switch (*s)
        {
        case 'I':
            count[0]++;
            sum+=1;
            break;
        case 'V':
            count[1]+=1;
            sum+=5;
            break;
        case 'X':
            count[2]+=1;
            sum+=10;
            break;
        case 'L':
            count[3]+=1;
            sum+=50;
            break;
        case 'C':
            count[4]+=1;
            sum+=100;
            break;
        case 'D':
            count[5]+=1;
            sum+=500;
            break;
        case 'M':
            count[6]+=1;
            sum+=1000;
            break;
        default:
            break;
        }
        s++;
    }
    s--;
    i=0;
    //计算错误的I
    while(s>=p&&*s == 'I'){
        i++;
        s--;
    }
    temp = count[0]-i;
    sum-=2*temp;
    i=0;
    printf("%d ",sum);
    //计算错误的X

    if(count[3]!=0){
        while(s>=p&&*s != 'L')
            s--;
        if(s-1>=p&&*(s-1) == 'X')
            sum-=20;
    }
    
    if(count[4]!=0){
        while(s>=p&&*s != 'C')
            s--;
        if(s-1>=p&&*(s-1) == 'X')
            sum-=20;
    }
    
    if(count[5]!=0){
        while(s>=p&&*s != 'D')
            s--;
        if(s-1>=p&&*(s-1) == 'C')
            sum-=200;
    }

    if(count[6]!=0){
        while(s>=p&&*s != 'M')
            s--;
        if(s-1>=p&&*(s-1) == 'C')
            sum-=200;
    }
    return sum;
}

int main(){
    printf("%d",romanToInt("MMCCCXCIX"));
}

/* printf("%d ",sum);
    i=0;
    if(count[4]!=0){
        while(s>=p&&*s != 'C')
            s--;
        if(s-1>=p&&*(s-1) == 'X'){
            s--;
            while(s>=p&&*s != 'C')
                s--;
        }
        if(*(s+1)=='D' || *(s+1)=='M')
            sum-=200*count[4];
        else{
            while(s>=p&&*s == 'C'){
                i++;
                s--;
            }
            temp = count[4]-i;
            sum-=200*temp;
        }
    }
    return sum;  
     while(s>=p&&*s == 'V')
        s--;
    while(s>=p&&*s == 'I')
        s--;
    while(s>=p&&*s == 'X')
        s--;
    while(s>=p&&*s == 'I')
        s--;
    while(s>=p&&*s == 'L')
        s--;
    if(*s == 'X'){
        sum-=20;
        s--;
    }
    while(s>=p&&*s == 'C')
        s--;
    if(*s == 'X'){
        sum-=20;
        s--;
    }
    while(s>=p&&*s == 'D')
        s--;
    if(*s == 'C'){
        sum-=200;
        s--;
    }
    while(s>=p&&*s == 'M')
        s--;
    if(*s == 'C'){
        sum-=200;
        s--;
    }
    return sum;*/


