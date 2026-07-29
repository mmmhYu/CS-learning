#include<stdio.h>
#include<string.h>
/*char* convert(char* s, int numRows) {
    int i,nums,rest,letters = strlen(s),step,k=0;
    nums = letters/(2*numRows-2);
    rest = letters%(2*numRows-2);
    printf("%s",*s);
    while(k*(2*nums-2) <= letters){
        printf("%s",(nums-2)," ");
        printf("%s",*(s+2*nums-2));
    }
    
    for(i=0;i<n-2){
        printf('\n');
        k=0;
        step=0;
        printf("%s",*(p+i+1));
        while(k%2?((k+1)/2*(2*nums-2))-i:((k+1)/2*(2*nums-2))+i <= letters){
            if(k%2 == 0){
                k++;
                printf("%s",(n-2-i)," ");
                printf("%s",*(s+(k+1)/2*(2*nums-2)-i));
            }
            else{
                k++;
                printf("%s",i," ");
                printf("%s",*(s+(k+1)/2*(2*nums-2)+i));
            }
        }
    }
    printf('\n');
    for(i=0;i<nums){
        printf("%s",*(s+(2*i+1)*(n-1)));
        printf("%s",(n-2)," ");
    }
}*/

char* convert(char* s, int numRows){
    char S[1000][1000] = " ";
    int i,j,letters = strlen(s),n = letters/(2*numRows-1),r = letters%(2*numRows-1);
    if(numRows == 1 || letters == 1)
        return s;
    for(i=0;i<n;i++){
        for(j=0;j<numRows;j++){
            S[j][i]=*(s++);
        }
        for(j=1;j<numRows-1;j++){
            S[numRows-1-j][j] = *(s++);
        }
    }
    for(i=0;i<r;i++){
        S[i][n*(numRows-1)+1] = *(s++);
    }
    if(r>numRows){
        r -= numRows;
        for(i=1;i<=r;i++){
            S[numRows-1-i][n*(numRows-1)+1+i] = *(s++);
        }
    return S;
    }
}

