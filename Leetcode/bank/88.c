#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int index = m--+n---1;
    while (m >= 0 && n >= 0){
        nums1[index--] = nums1[m]>nums2[n]?nums1[m--]:nums2[n--];
    }
    for(int k = n; k >= 0; k--)
        nums1[index--] = nums2[k];  
}

/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(m == 0){
        for(int k = 0; k < n; k++)
            nums1[k] = nums2[k];
        return;
    }

    int i = 0 , j = 0, cpy[m], cnt = 0;
    for(int k = 0; k < m; k++)
        cpy[k] = nums1[k];
    while (i < m && j < n){
        nums1[cnt++] = cpy[i]<nums2[j]?cpy[i++]:nums2[j++];
    }
    if(i < m){
        for(int k = i; k < m; k++)
            nums1[cnt++] = cpy[k];
    }
    else{
        for(int k = j; k < n; k++)
            nums1[cnt++] = nums2[k];
    }
}*/

int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    int m = 3;
    int n = 3;

    merge(nums1, m + n, m, nums2, n, n);

    printf("Merged array: ");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}