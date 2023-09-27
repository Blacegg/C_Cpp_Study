#pragma once
#include <iostream>
using namespace std;

/***********************************************************************
 * @brief  class MyArray
 * @tparam T
 ***********************************************************************/
template <typename T>
class MyArray
{
public:
    // 构造函数
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // 拷贝函数
    MyArray(const MyArray &array)
    {
        this->pAddress = new T[array.m_Capacity];
        this->m_Size = array.m_Size;
        this->m_Capacity = array.m_Capacity;
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = array.pAddress[i];
        }
    }

    // =重载
    MyArray &operator=(const MyArray &array)
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        this->pAddress = new T[array.m_Capacity];
        this->m_Size = array.m_Size;
        this->m_Capacity = array.m_Capacity;
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = array.pAddress[i];
        }
        return *this;
    }

    // []重载
    T &operator[](const int index)
    {
        return this->pAddress[index];
    }

    // 尾插法
    void Push_back(const T &val)
    {
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // 尾删法
    void Pop_back()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    // 获取数组大小
    int GetSize()
    {
        return this->m_Size;
    }

    // 获取数组容量
    int GetCapacity()
    {
        return this->m_Capacity;
    }

    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }

private:
    T *pAddress;    // 指向一个堆空间，这个空间存储真正的数据
    int m_Capacity; // 容量
    int m_Size;     // 大小
};