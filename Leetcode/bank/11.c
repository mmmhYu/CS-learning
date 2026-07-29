#include<stdio.h>

int maxArea(int* height, int heightSize){
    int i=0,j=heightSize-1,area,Max_Area = 0;
    while(i<j){
        area = (j-i)*(height[i]>=height[j]?height[j]:height[i]);
        Max_Area = Max_Area > area ? Max_Area : area;
        if(height[i]<=height[j])
            i++;
        else
            j--;
    }
    return Max_Area;
}

int main() {
    // 测试用例1 官方样例 [1,8,6,2,5,4,8,3,7]，预期49
    int arr1[] = {1,8,6,2,5,4,8,3,7};
    int sz1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("用例1输出：%d，预期49\n", maxArea(arr1, sz1));

    // 测试用例2 [1,1]，预期1
    int arr2[] = {1,1};
    int sz2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("用例2输出：%d，预期1\n", maxArea(arr2, sz2));

    return 0;
}