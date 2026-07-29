#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sort(char* str,char* p,char *lst,char *cpt){
    int i = 0,count = 0,len = 0,max = 0,k=0;
    char temp[30];
    if(*str == ' ')
        while(*str == ' '){str++;}
    while(*str != 0){
        cpt[k++] = *str;
        len = 0;
        while(*str != ' ' && *str != 0){
            p[i++] = *str;
            temp[len++] = *str++;
        }
        temp[len+1] = 0;
        count++;

        if(len > max){
            max = len;
            strcpy(lst,temp);
        }

        if(*str == 0)
            break;
        else{
            p[i++] = ' ';
            while(*str == ' ')
                str++;
        }
    }
    p[i] = 0;
    cpt[k] = 0;
    return count;
}

