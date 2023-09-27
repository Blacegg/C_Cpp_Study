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
    // ���캯��
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    // ��������
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

    // =����
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

    // []����
    T &operator[](const int index)
    {
        return this->pAddress[index];
    }

    // β�巨
    void Push_back(const T &val)
    {
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // βɾ��
    void Pop_back()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    // ��ȡ�����С
    int GetSize()
    {
        return this->m_Size;
    }

    // ��ȡ��������
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
    T *pAddress;    // ָ��һ���ѿռ䣬����ռ�洢����������
    int m_Capacity; // ����
    int m_Size;     // ��С
};