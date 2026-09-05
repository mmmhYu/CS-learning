//#pragma once

#include<iostream>
#include<vector>
#include<string>
#include <stdexcept>

using namespace std;

template <typename T>
class myarray
{
private:
    T *arr;
    int size;
    int nums;

public:
    myarray(int n):size(n),nums(0)
    {
        cout << "constructor" << endl;
        arr = new T[size];
    }
    //作参数不用<T>？
    myarray(const myarray<T>& myarr):size(myarr.size),nums(myarr.nums)
    {
        arr = new T[size];
        for(int i = 0; i < size; i++)
            arr[i] = myarr.arr[i];

    }

    ~myarray()
    {
        cout << "destructor" << endl;
        if(arr)
        {
            delete[] arr;
            arr = NULL;
        }
            
    }
    
    const myarray& operator = (const myarray<T>& rhs);
    //尝试类外实现

    T& operator[](int index)
    {
        if(index >= nums || index < 0)
            throw std::out_of_range("myarray index out of range");

        return arr[index];
    }

    int push(T ele)
    {
        if(nums == size)
        {
            cout << "FULL" << endl;
            return 0;
        }

        arr[nums++] = ele;
        return 1;

    }

    int pop(int &reciever){
        if(!nums)
        {
            cout << "EMPTY" << endl;
            return 0;
        }

        reciever = arr[--nums];
        return 1;
    }

    int get_size()
    {
        return size;
    }

    int get_nums()
    {
        return nums;
    }
    
};

//类外实现赋值:
template <typename T>
const myarray<T>& myarray<T>:: operator=(const myarray<T>& rhs)
{
    if(this == &rhs)
        return *this;

    if(arr)
    {
        delete[]arr;
        arr = NULL;
    }    

    size = rhs.size;
    delete[] arr;
    arr = new T[sizs];

    for(int i = 0; i < size; i++)
        cpy.arr[i] = rhs.arr[i];

    return *this;
}