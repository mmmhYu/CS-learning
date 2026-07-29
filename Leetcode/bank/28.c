#include<stdio.h>
#include<stdlib.h>

int strStr(char* haystack, char* needle) {
    int ph = 0,pn = 0,t,k=0,con;
    while(haystack[ph]!=0){
        if(haystack[ph] == needle[pn]){
            t = ph;
            k=0;
            con = 0;
            while (haystack[ph] == needle[pn] && needle[pn]!=0){
                if(con==0 && haystack[ph] == needle[0]){
                    k = ph;
                    con = 1;
                }  
                pn++;
                ph++;
            }
            if(needle[pn] == 0)
                return t;
            else{
                if(k!=0)
                    ph = k;
                else
                    ph++;
                pn = 0;
            }
        }
        else
            ph++;
    }
    return -1;
}


int main() {
    // 测试用例 1
    char h1[] = "mississippi";
    char n1[] = "issip";
    printf("测试1：%d\n", strStr(h1, n1));  // 预期 0

    // 测试用例 2
    char h2[] = "leetcode";
    char n2[] = "leeto";
    printf("测试2：%d\n", strStr(h2, n2));  // 预期 -1

    // 测试用例 3
    char h3[] = "hello";
    char n3[] = "ll";
    printf("测试3：%d\n", strStr(h3, n3));  // 预期 2

    // 测试用例 4
    char h4[] = "abcde";
    char n4[] = "de";
    printf("测试4：%d\n", strStr(h4, n4));  // 预期 3

    // 测试用例 5
    char h5[] = "a";
    char n5[] = "a";
    printf("测试5：%d\n", strStr(h5, n5));  // 预期 0

    return 0;
}