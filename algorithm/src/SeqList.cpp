#include "SeqList.h"

//默认构造函数
template<class T>
SeqList<T>::SeqList()
{
    Data = nullptr;
    Length = 0;
    Size = 0;
}

//带参构造函数
template<class T>
SeqList<T>::SeqList(T *Data, int Length, int Size)
{
    this->Data = Data;
    this->Size = Size;
    this->Length = Length;
    this->Data = new T[Size+1];
    for(int i=0;i<Length;i++)
        this->Data[i+1] = Data[i];
}

//析构函数
template<class T>
SeqList<T>::~SeqList()
{
    if(Data!=nullptr)
        delete []Data;
    Data = nullptr;
    Size = 0;
    Length = 0;
}

//获取顺序表中的数据
template<class T>
T* SeqList<T>::get_data()
{
    return Data;
}

//获取指定位置数据
template<class T>
T SeqList<T>::get_element(int loca)
{
    return Data[loca];
}

//获取顺序表长度
template<class T>
int SeqList<T>::get_length()
{
    return Length;
}

//向指定位置插入元素
template<class T>
void SeqList<T>::ele_insert(T data, int loca)
{
    if(loca>Length+1)
        throw "out of size";
    if(Length+1>=Size)
    {
        T* p = Data;
        Data = new T[Size+10];
        for(int i=1;i<=Length;i++)
            Data[i] = p[i];
        delete []p;
        p = nullptr;
        Size+=10;
    }
    for(int i=Length+1;i>loca;i--)
        Data[i] = Data[i-1];
    Data[loca] = data;
    Length++;
}

//删除指定位置元素
template<class T>
void SeqList<T>::ele_delete(int loca)
{
    if(loca<1 || loca>Length)
        throw"out of size";
    for(int i=loca;i<Length;i++)
        Data[i] = Data[i+1];
    Length--;
}

//查询顺序表中是否存在某个元素,存在则返回下标（存在多个返回第一个），不存在则返回-1
template<class T>
int SeqList<T>::ele_locate(T data)
{
    for(int i=1;i<=Length;i++)
    {
        if(Data[i] == data)
            return i;
    }
    return -1;
}

//修改顺序表中指定元素的值
template<class T>
void SeqList<T>::ele_modify(T data, int loca)
{
    if(loca<1 || loca>Length)
        throw"out of size";
    Data[loca] = data;
}

//对顺序表排序
template<class T>
void SeqList<T>::sort_list()
{
    for(int i=1;i<=Length;i++)
    {
        for(int j=i+1;j<=Length;j++)
        {
            if(Data[i]>Data[j])
            {
                int temp = Data[i];
                Data[i] = Data[j];
                Data[j] = temp;
            }
        }
    }
}