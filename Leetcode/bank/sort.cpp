#include<iostream>
#include<vector>
#include<utility>
using std::vector;
using std::swap;

void quick_sort(vector<int>& arr,int l,int r)
{
    if(l+1 >= r)
        return;

    int pivot = arr[l],left = l,right = r-1;

    while(left < right){
        while(right > left && arr[right] >= pivot)
            right--;
        arr[left] = arr[right];

        while(left < right && arr[left] <= pivot)
            left++;
        arr[right] =arr[left];
    }

    arr[left] = pivot;

    quick_sort(arr,l,left);
    quick_sort(arr,left+1,r);

}

void quick_sort_landr(vector<int>& arr,int l,int r)
{
    if(l >= r)
        return;

    int pivot = arr[l],left = l,right = r;

    while(left < right){
        while(right > left && arr[right] >= pivot)
            right--;
        arr[left] = arr[right];

        while(left < right && arr[left] <= pivot)
            left++;
        arr[right] =arr[left];
    }

    arr[left] = pivot;

    quick_sort_landr(arr,l,left-1);
    quick_sort_landr(arr,left+1,r);

}

void quick_sort_exchange(vector<int>& arr,int l,int r)
{
    if(l+1 >= r)
        return;

    int left = l,right = r-1,pivot = arr[l];

    while(left < right){
        while(left < right && arr[right] >= pivot)
            right--;
        while(left < right && arr[left] <= pivot)
            left++;

        swap(arr[left],arr[right]);
    }

    swap(arr[left],arr[l]);

    quick_sort_exchange(arr,l,left);
    quick_sort_exchange(arr,left+1,r);
}

void merge_sort(vector<int>& arr,vector<int>& sup,int l,int r)
{
    if(l+1 >= r)
        return;

    int mid = l+(r-l)/2;

    //这里注意左右区间，虽然都是左闭右开，但是和快速排序是不一样的
    //我一开始就搞错了
    merge_sort(arr,sup,l,mid);
    merge_sort(arr,sup,mid,r);

    int i = l,j = mid,index = l;
    while(i<mid || j<r){
        if(i == mid){
            while(j < r)
                sup[index++] = arr[j++];
        }  
        else if(j == r){
            while(i < mid)
                sup[index++] = arr[i++];
        }
        else
            sup[index++] = arr[i]<=arr[j] ? arr[i++] : arr[j++];
    }

    for(int k = l; k < r; k++)
        arr[k] = sup[k];

}

void merge_sort(vector<int>& arr,vector<int>& sup,int l,int r)
{
    if(l >= r)
        return;

    int mid = l+(r-l)/2;

    merge_sort(arr,sup,l,mid);
    merge_sort(arr,sup,mid+1,r);

    int i = l,j = mid+1,index = l;
    while(i<=mid || j<=r){
        if(i > mid){
            while(j <= r)
                sup[index++] = arr[j++];
        }  
        else if(j > r){
            while(i <= mid)
                sup[index++] = arr[i++];
        }
        else
            sup[index++] = arr[i]<=arr[j] ? arr[i++] : arr[j++];
    }

    for(int k = l; k <= r; k++)
        arr[k] = sup[k];

}