#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*int maxProfit(int* prices, int pricesSize) {
    int fast,slow,prof = 0;
    for(fast = 0; fast < pricesSize-1; fast++){
        if(prices[fast] < prices[fast+1])
            break;
    }
    if(fast == pricesSize-1)  
        return 0;
    for(slow = 0; slow < pricesSize-1;){
        for(fast = slow+1; fast < pricesSize; fast++){
            if(prices[fast] > prices[slow] && (fast == pricesSize-1 || prices[fast] > prices[fast+1])){
                prof += prices[fast]-prices[slow];
                slow = fast+1;
                break;
            }
            if(prices[fast] < prices[slow]){
                slow = fast;
                break;
            }
        }
        if(fast == pricesSize)
            slow++;
    }
    return prof;
}*/

int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 1)
        return 0;
    int each_prof[pricesSize-1], prof = 0,slow,fast;
    for(slow = 0; slow < pricesSize-1; slow++)
        each_prof[slow] = 0;
    for(slow = 0; slow < pricesSize-1; slow++){
        for(fast = slow+1; fast < pricesSize; fast++){
            if(prices[fast] <= prices[slow] || prices[fast] < prices[fast-1]){
                slow = fast-1;
                break;
            }
            else if(prices[fast] > prices[slow])
                each_prof[slow] = each_prof[slow]>(prices[fast]-prices[slow])?each_prof[slow]:prices[fast]-prices[slow];
        }
        if(fast == pricesSize)
            break;
    }
    for(fast = 0;fast < pricesSize-1; fast++){
        printf("%d\n",each_prof[fast]);
        prof += (each_prof > 0)*each_prof[fast];
    }   
    return prof;
}

int main()
{
    // 测试数据:
    // prices = [7,1,5,3,6,4]
    int prices[] = {2,1,4,5,2,9,7};

    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int ans = maxProfit(prices, pricesSize);

    printf("answer = %d\n", ans);

    return 0;
}