#include<stdbool.h>
#include<math.h>
#include<stdio.h>
/*bool isPalindrome(int x) {
    int k=1,xx=x,n,i,count=0;
    if(x < 0)
        return false;
    else{
        while(xx>=10){
        xx/=10;
        k++;
        }
        n=(k+1)/2;
        for(i=0;i<n;i++){
            count += x/(int)pow(10,(k-1-i))%10 == x%(int)pow(10,i+1)/(int)pow(10,i);
        }
        if(count == n)
            return true;
        else
            return false;
    } 
}*/

/*bool isPalindrome(int x) {
    char *foward,*backward;
    x=(char)x;
    sprintf(foward, "%d", x);
    sprintf(backward, "%d", x);
    while(*backward != 0)
        backward++;
    backward--;
    while()
}*/

bool isPalindrome(int x) {
    if(x<0)
        return false;
    int k=0,p=x;
    while(p!=0){
        k=k*10+p%10;
        p/=10;
    }
    if(k == x)
        return true;
    else
        return false;
}