#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void my_strcpy(char *dest,char *src){
    int i = 0;
    while (*(src+i) != '\0'){
        *(dest+i) = *(src+i);
        i++;
    }
    *(dest+i) = '\0';
}

int my_strcmp(char *a,char *b){
    int i = 0;
    while (*(a+i) != '\0' && *(b+i) != '\0' && *(a+i) == *(b+i)){
        i++;
    }
    return *(a+i)-*(b+i);
}

typedef struct Contact{
    char name[31];
    char num[31];
}con;

struct tele_book{
    int Max_Size;
    int Tmp_Size;
    con **tele;
};

int tele_exp(struct tele_book *tb){
    tb->Max_Size += 5;
    con **new_tele = realloc(tb->tele,(tb->Max_Size)*sizeof(con*));
    /*if(!new_tele){
        printf("malloc failed!\n");
        return 0;
    }*/
    tb->tele = new_tele;
    return 1;
}

int tele_add(char *name,char *num,struct tele_book *tb){
    if(tb->Tmp_Size == tb->Max_Size){
        if(tele_exp(tb) == 0)
            return 0;
    }
    for(int i=0;i<tb->Tmp_Size;i++){
        if(my_strcmp(tb->tele[i]->name,name) == 0)
            return 0;
    }
    con *p = (con*)malloc(sizeof(con));
    /*if(!p){
        printf("add failed!\n");
        return 0;
    }*/
    my_strcpy(p->name,name);
    my_strcpy(p->num,num);
    tb->tele[tb->Tmp_Size++] = p;
    return 1;
}

int tele_update(char *name,char *num,struct tele_book *tb,char *os){
    int i = 0;
    if(tb->Tmp_Size == 0)
        return 0;
    while(i<tb->Tmp_Size && strcmp(tb->tele[i]->name,name))
        i++;
    if(i == tb->Tmp_Size){
        return 0;
    }
    my_strcpy(tb->tele[i]->num,num);
    return 1;
}

int tele_del(char *name,struct tele_book *tb,char *os){
    int i = 0;
    if(tb->Tmp_Size == 0)
        return 0;
    while(i<tb->Tmp_Size && my_strcmp(tb->tele[i]->name,name))
        i++;
    if(i == tb->Tmp_Size){
        sprintf(os + strlen(os),"NOT FOUND\n");
        return 0;
    }
    free(tb->tele[i]);
    for(int j=i;j<tb->Tmp_Size-1;j++)
        tb->tele[j] = tb->tele[j+1];
    tb->Tmp_Size--;
    return 1;
}

int tele_find(char *name,struct tele_book *tb,char *os){
    if(tb->Tmp_Size == 0)
        return 0;
    int i = 0;
    while(i<tb->Tmp_Size && my_strcmp(tb->tele[i]->name,name))
        i++;
    if(i == tb->Tmp_Size){
        sprintf(os + strlen(os),"NOT FOUND\n");
        return 0;
    }
    sprintf(os + strlen(os), "%s\n",tb->tele[i]->num);
    return 1;
}

int tele_print(struct tele_book *tb,char *os){
    if(tb->Tmp_Size == 0){
        sprintf(os + strlen(os),"EMPTY\n");
        return 0;
    }
    for(int i=0;i<tb->Tmp_Size;i++){
        sprintf(os + strlen(os), "%s:%s ",tb->tele[i]->name,tb->tele[i]->num);
    }
    sprintf(os + strlen(os),"\n");
    return 1;
}

int main(){
    int q = 0;
    char op[10];
    char os[1000] = {0};
    scanf("%d",&q);
    struct tele_book tb;
    tb.Max_Size = 10;
    tb.Tmp_Size = 0;
    tb.tele = malloc(tb.Max_Size*sizeof(con*));
    for(int i=0;i<q;i++){
        scanf("%s",op);
        if (!my_strcmp(op,"add")){
            char name[31];
            char num[31];
            scanf("%s",name);
            scanf("%s",num);
            tele_add(name,num,&tb);
            while(getchar() != '\n');
            continue;
        }
        if (!my_strcmp(op,"update")){
            char name[31],num[31];
            scanf("%s",name);
            scanf("%s",num);
            tele_update(name,num,&tb,os);
            while(getchar() != '\n');
            continue;
        }
        if (!my_strcmp(op,"delete")){
            char name[31];
            scanf("%s",name);
            tele_del(name,&tb,os);
            while(getchar() != '\n');
            continue;
        }
        if (!my_strcmp(op,"find")){
            char name[31];
            scanf("%s",name);
            tele_find(name,&tb,os);
            while(getchar() != '\n');
            continue;
        }
        if (!my_strcmp(op,"print")){
            tele_print(&tb,os);
            while(getchar() != '\n');
            continue;
        }
    }
    if(strlen(os) > 0)
        {
            printf("%s", os);
            fflush(stdout);
        }
}

