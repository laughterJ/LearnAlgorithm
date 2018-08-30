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

//删除指定位置元素
template<class T>
void SeqList<T>::ele_delete(int loca)
{
    for(int i=loca;i<Length;i++)
        Data[i] = Data[i+1];
    Length--;
}

//向指定位置插入元素
template<class T>
void SeqList<T>::ele_insert(int loca,T data)
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






