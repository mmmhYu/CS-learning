#include<stdio.h>
#include<stdlib.h>

char* minWindow(char* s, char* t) {
    char *p = s, *q = s, *r = t;
    int ex[128]={0},win[128] = {0}, cnt = 0,len,tmp_cnt = 0;
    while(*r){
        cnt++;
        ex[*(r)]++;
        r++;
    }
    char *res = malloc(100);

    while(*p){
        tmp_cnt = 0;
        if(ex[*p]){            
            q = p;
            while(*q && tmp_cnt < cnt){
                if(ex[*q] > win[*q]){
                    
                    tmp_cnt++;
                }
                win[*q]++;
                q++;
            }
        }
        if(tmp_cnt == cnt)
            break;
        if(tmp_cnt != cnt)
            return "";
        p++;
    }
    q--;
    if(!(*p))
        return 0;
    len = q-p+1;
    char *l = p;
    r = q;

    while(*r){
        while(*l&&!ex[*l])
            l++;
        win[*(l++)]--;
        if(win[*(l-1)] < ex[*(l-1)]){
            r++;
            tmp_cnt--;
            while(*r && *r != *(l-1)){
                if(ex[*r]){
                    win[*r]++;
                    tmp_cnt++;
                }
                r++;
            }
            if(*r == *(l-1) && ex[*r] > ex[*r])
                
                tmp_cnt++;
        }
        win[*(l-1)]++;
        if(tmp_cnt == cnt && len > r-l+(*r!=0)){
            p = l;
            q = r;
        }
    }
    l = p;
    r = q;
    int i =0;
    while(l <= r){
        res[i++] = *(l++);
    }
    res[i] = 0;
    return res;   
}

int main() {

    char s4[] = "bbaac";
    char t4[] = "baa";

    char* ans;

    ans = minWindow(s4, t4);
    printf("s = %s, t = %s -> %s\n", s4, t4, ans);

    free(ans);

    return 0;
}