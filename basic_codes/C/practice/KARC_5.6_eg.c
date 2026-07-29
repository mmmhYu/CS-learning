#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//这里是对于qsort函数的内部实现没有搞清楚
//qsort函数 调用cmp的时候 传入的参数是相邻数组元素的首地址
//这里的数组元素都是char* 取一次地址 自然变成char**
int my_cmp(const void* a,const void* b){
    char *pa = *(char**)a;
    char *pb = *(char**)b;
    while(*pa!=0 && *pb!=0 && *pa==*pb){
        pa++;
        pb++;
    }
    return *pa-*pb;
}

int readLines(char *str[], int maxLines){
    char c;
    int i = 0;
    while(i < maxLines){
        char tmp[50];
        fgets(tmp,50,stdin);
        int len = strlen(tmp);
        tmp[len-1] = 0;
        str[i] = (char*)malloc(len);
        strcpy(str[i],tmp);
        i++;
    }
    return i;
}

void sortStrings(char *str[], int n){
    qsort(str,n,sizeof(char*),my_cmp);
//内部实现
//...
//cmp(&str[i],&str[i+1]);
//...
//至于为什么要传地址 gpt说也是为了节省内存空间。。。
}

int main(){
    char *str[4];
    readLines(str,4);
    sortStrings(str,4);
//可以注意一下这里的参数传递：不要把这个想成是什么字符串数组 再想什么数组名退化
//很简单 就是把他想成是一个数组 只不过里面的元素是字符指针（char*）
//那么这里的参数传递就是简单的数组名传递 
//而函数里面是通过比较指针指向字符串的字典序（类比整数数组的大小比较）来排序
//本质就是交换不同位置的指针（类比整数排序）参数传递是没有任何问题的

//另外 这里应当明白的是为什么使用这样交换指针的逻辑：交换字符串涉及的内存占用太大
//以及修改指针和整数在数组内的排序就是一样的
//只不过整数直接比大小 这里比较的对象的是解引用后的内容
    for(int i = 0; i < 4; i++)
        printf("%s\n",str[i]);
}
