#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

char **MaxSubstr(char *s,char *t,int *size){
    char **res;
    int max_len = 0,nums = 0,
        slen = strlen(s),tlen = strlen(t),
        dp[slen+1],idxarr[20];
    //idxarr用于存储所有符合要求的子串的起始下标,nums是子串个数
    memset(dp,0,sizeof(dp));

    for(int idx = 1-tlen; idx < slen; idx++){
        int uplim = min((slen-idx),tlen),sublim = max(-idx,0),subdp[tlen+1];
        memset(subdp,0,sizeof(subdp));

        for(int i = sublim; i < uplim; i++)
            if(s[idx+i] == t[i])
                subdp[i+1] = subdp[i] + 1;
        
        for(int i = sublim; i < uplim; i++)
            dp[idx+i+1] = max(dp[idx+i+1],subdp[i+1]);

    }

    for(int i = 0; i < slen; i++){
        if(dp[i+1] > max_len){
            nums = 0;
            max_len = dp[i+1];
        }

        if(max_len == dp[i+1])
            idxarr[nums++] = i - max_len + 1;
    }

    if(!max_len){
        *size = 0;
        return NULL;
    }

    res = (char**)malloc(nums*sizeof(char*));
    for(int i = 0; i < nums; i++){
        int idx = idxarr[i];
        res[i] = (char*)malloc((max_len+1)*sizeof(char));
        for(int j = 0; j < max_len; j++)
            res[i][j] = s[idx + j];

        res[i][max_len] = 0;
    }

    *size = nums;
    return res;
}

void test(char *s, char *t){
    int size = 0;
    char **res = MaxSubstr(s, t, &size);

    printf("s = \"%s\"\n", s);
    printf("t = \"%s\"\n", t);
    printf("size = %d\n", size);

    for(int i = 0; i < size; i++){
        printf("res[%d] = \"%s\"\n", i, res[i]);
        free(res[i]);
    }

    free(res);
    printf("--------------------\n");
}

int main(){

    // 1. 最长公共子串在两串中间
    test("123abc456", "xxxabcyyy");
    // 期望：abc

    // 2. 公共子串在 s 开头、t 结尾
    test("abcdef", "xyzabc");
    // 期望：abc

    // 3. 公共子串在 s 结尾、t 开头
    test("xyzabcdef", "def123");
    // 期望：def

    // 4. 有多个长度相同、内容不同的最长公共子串
    test("abcXXXdefYYYghi", "abc000def111ghi");
    // 期望：
    // abc
    // def
    // ghi

    // 5. 连续性测试：相同字符很多，但最长连续段有限
    test("abcXdef", "abcYdef");
    // 期望：
    // abc
    // def

    // 6. 大量重复字符
    test("aaaaaa", "aaa");
    // 按你当前“按 s 中出现位置”统计：
    // aaa
    // aaa
    // aaa
    // aaa

    // 7. 一个字符串明显比另一个长
    test("xxxxxxxxabcdefxxxxxxxx", "abcdef");
    // 期望：abcdef

    // 8. t 比 s 长很多
    test("abc", "xxxxxxxxabcxxxxxxxx");
    // 期望：abc

    // 9. 只有一个公共字符，而且在边界
    test("abcdef", "xxxxxxf");
    // 期望：f

    // 10. 完全无公共字符
    test("abcdef", "XYZ123");
    // 期望：size = 0

    // 11. 单字符相同
    test("x", "x");
    // 期望：x

    // 12. 单字符不同
    test("x", "y");
    // 期望：size = 0

    // 13. 用来检查“连续”而不是“子序列”
    test("abcdef", "ace");
    // 期望有三个长度为1的结果：
    // a
    // c
    // e

    // 14. 最长公共部分需要明显错位才能找到
    test("xxxxabcd", "abcdyyyy");
    // 期望：abcd

    return 0;
}