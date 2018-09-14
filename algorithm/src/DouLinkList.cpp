#include "DouLinkList.h"

//默认构造函数
template<class T>
DouLinkList<T>::DouLinkList()
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Head->Prior = nullptr;
}

//带参构造函数
template<class T>
DouLinkList<T>::DouLinkList(T* data,int Len)
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Head->Prior = nullptr;
    Node<T>* sign = Head;
    for(int i=0;i<Len;i++)
    {
        Node<T>* p = new Node<T>;
        p->Data = data[i];
        p->Prior = sign;
        p->Next = sign->Next;
        sign->Next->Prior = p;
        sign->Next = p;
        sign = p;
    }
}

//析构函数
template<class T>
DouLinkList<T>::~DouLinkList()
{
    if(Head)
    {
        while(Head->Next)
            ele_delete(1);
        delete Head;
        Head = nullptr;
    }
}

//获取头节点
template<class T>
Node<T>* DouLinkList<T>::get_head()
{
    return Head;
}

//向指定位置插入元素
template<class T>
void DouLinkList<T>::ele_insert(T data, int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    Node<T>* p = new Node<T>;
    p->Data = data;
    p->Next = sign->Next;
    p->Prior = sign;
    sign->Next->Prior = p;
    sign->Next = p;
}

//删除指定位置元素
template<class T>
void DouLinkList<T>::ele_delete(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    sign->Prior->Next = sign->Next;
    sign->Next->Prior = sign->Prior;
    delete sign;
    sign = nullptr;
}

//查询指定元素是否在链表中，若存在，返回第一个的位置，若不存在，返回-1
template<class T>
int DouLinkList<T>::ele_locate(T data)
{
    Node<T>* sign = Head->Next;
    int posi = 1;
    while(sign)
    {
        if(sign->Data==data)
            return posi;
        sign = sign->Next;
        posi++;
    }
    return -1;
}

//将指定位置元素修改为指定值
template<class T>
void DouLinkList<T>::ele_modify(int posi, T data)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    sign->Data = data;
}

//获取链表尾部元素
template<class T>
Node<T>* DouLinkList<T>::get_back()
{
    Node<T>* sign = Head;
    while(sign->Next)
        sign = sign->Next;
    return sign;
}

//移动到链表指定位置
template<class T>
Node<T>* DouLinkList<T>::move_to(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
    {
        sign = sign->Next;
        if(sign == nullptr)
            throw"out of size";
    }
    return sign;
}