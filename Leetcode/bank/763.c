#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int* partitionLabels(char* s, int* returnSize) {
    int len = strlen(s),*res = malloc(100*sizeof(int));
    char *l = s,*r = s+len-1, *rm = s;
    *returnSize = 0;
    while(l <= r){
        while(*r != *l)
            r--;
        for(char *p = r+1; p <= s+len-1; p++){
            char *q = l;
            while(q < r){
                if(*q == *p)
                    break;
                q++;
            }
            if(q < r)
                r = p;
        }
        res[(*returnSize)++] = r-l+1;
        l = r+1;
        r = s+len-1;
    }
    return res;
}*/

int* partitionLabels(char* s, int* returnSize) {
    int len = strlen(s),*res = malloc(100*sizeof(int)),last[26];
    char *l = s,*r = s+len-1;
    *returnSize = 0;
    for(int i = 1; i <= len; i++){
        last[*(s+i-1)-'a'] = i;
    }
    char *p = s;
    int up = last[(*p)-'a'],ori = 0;
    while(p < s+len){
        up = last[(*p)-'a'];
        while(p < s+up){
            up = up>last[(*p)-'a']?up:last[(*p)-'a'];
            p++;
        }
        res[(*returnSize)++] = up-ori;
        ori = up;
    }
    return res;
}

int main()
{
    char s[] = "eccbbbbdec";

    int returnSize = 0;

    int *ans = partitionLabels(s, &returnSize);


    printf("partition count = %d\n", returnSize);

    printf("result: ");
    for(int i = 0; i < returnSize; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");


    free(ans);

    return 0;
}