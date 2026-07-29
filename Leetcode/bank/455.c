#include<stdio.h>
#include<stdlib.h>

/*void sort(int *a,int len){
    int i,j,tmp_max,k,t;
    for(i = 0 ; i < len-1 ; i++){
        tmp_max = a[i];
        k = i;
        for(j = i+1 ; j < len ; j++){
            if(a[j] > tmp_max){
                k = j;
                tmp_max = a[k];
            }
        }
        if(k != i){
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}*/

static int cmpDesc(const void* pa, const void* pb) {
    int a = *(const int*)pa;
    int b = *(const int*)pb;
    return a - b;
}

//有两种视角 一个是站在饼干的视角 最大的饼干要给最大的胃袋
//          另一个站在孩子的视角 最小胃袋的孩子吃最小的饼干就可以了
//其实都是贪心算法 对于最大的饼干 给更小的胃袋收益不会更大
//对于最小胃袋的孩子同样 吃更大的饼干收益不会更大
//注：站在最小饼干 最大胃袋的视角 不太方便解决 当然也可以解释了 没有上面的简洁
//注意 两种视角对应两种排序方式 这个是降序排列
/*int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmpDesc);
    qsort(s, sSize, sizeof(int), cmpDesc);
    if(sSize == 0 || gSize == 0 || g[gSize-1] > s[0])
        return 0;
    int pg = 0, ps = 0, count = 0;
    while(pg < gSize && ps < sSize){
        if(s[ps] >= g[pg]){
            pg++;
            ps++;
            count++;
        }
        else
            pg++;
    }
    return count;
}*/

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g,gSize,sizeof(int),cmpDesc);
    qsort(s,sSize,sizeof(int),cmpDesc);
    int i = 0, j = 0;
    while(j < sSize && i < gSize){
        if(g[i] <= s[j])
            i++;
        j++;
    }
    return i;
}

int main() {
    // 测试用例1 样例
    int g1[] = {1,2};
    int s1[] = {1,2,3};
    int len_g1 = sizeof(g1) / sizeof(g1[0]);
    int len_s1 = sizeof(s1) / sizeof(s1[0]);
    printf("%d\n", findContentChildren(g1, len_g1, s1, len_s1));
}