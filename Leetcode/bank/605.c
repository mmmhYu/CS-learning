#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;
    if(flowerbedSize == 1)
        return flowerbed[0] + n < 2 ? 1 : 0;
    
    if(flowerbed[0] == 0 && flowerbed[1] == 0){
        n--;
        flowerbed[0] = 1;
    }
    if(flowerbed[flowerbedSize-1] == 0 && flowerbed[flowerbedSize-2] == 0)
        n--;
    for(i = 2; i < flowerbedSize-2; i++){
        if(flowerbed[i] == 1){
            i++;
            continue;
        }
        if(flowerbed[i] == 0 &&flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
            n--;
            i++;
        }
    }
    if(n <= 0)
        return 1;
    else
        return 0;
}


//尝试填充虚拟边界
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;
    flowerbed[-1] = 0;
    flowerbed[flowerbedSize] = 0;
    for(i = 0; i < flowerbedSize; i++){
        if(flowerbed[i] == 1){
            i++;
            continue;
        }
        if(flowerbed[i] == 0 &&flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
            n--;
            i++;
        }
    }
    if(n <= 0)
        return 1;
    else
        return 0;
}
