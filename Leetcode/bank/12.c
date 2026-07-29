#include<math.h>
#include<stdio.h>
#include<stdlib.h>
char* intToRoman(int num) {
    char letters[7]={'M','D','C','L','X','V','I'},*result,*cpy;
    int i=0,nums[7]={1000,500,100,50,10,5,1},t,k,j=0,n=2;
    result = (char*)malloc(20*sizeof(char));
    cpy = result;
    k = num/nums[i];
    while(j<k){
        *result = 'M';
        result++;
        j++;
    }
    num %= 1000;
    for(i=1;i<6;i+=2,n--){
        j = 0;
        k = num/(int)pow(10,n);
        num %= (int)pow(10,n);
        if(k == 9){
            *(result++) = letters[i+1];
            *(result++) = letters[i-1];
        }
        else if(k == 4){
            *(result++) = letters[i+1];
            *(result++) = letters[i];
        }
        else if(k>4 && k<9){
            *(result++) = letters[i];
            k -= 5;
            while((k--)>0)
                *(result++) = letters[i+1];
        }
        else{
            while((k--)>0)
                *(result++) = letters[i+1];
        }
    }
    *result = 0;
    return cpy;
}

int main(){
    printf("%s",intToRoman(1994));
}