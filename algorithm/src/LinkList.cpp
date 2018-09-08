#include "LinkList.h"

//默认构造函数
template<class T>
LinkList<T>::LinkList()
{
    Head = new Node<T>;
    Head->Next = nullptr;
}

//带参构造函数
template<class T>
LinkList<T>::LinkList(T* data, int len)
{
    Head = new Node<T>;
    Head->Next = nullptr;
    Node<T>* sign = Head;
    for(int i=0;i<len;i++)
    {
        Node<T>* p = new Node<T>;
        p->Data = data[i];
        p->Next = nullptr;
        sign->Next = p;
        sign = p;
    }
}

//析构函数
template<class T>
LinkList<T>::~LinkList()
{
    if(Head!=nullptr)
    {
        while(Head->Next!=nullptr)
            ele_delete(1);
        delete Head;
        Head = nullptr;
    }
}

//获取头节点
template<class T>
Node<T>* LinkList<T>::get_head()
{
    return Head;
}

//向指定位置插入元素
template<class T>
void LinkList<T>::ele_insert(T data, int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
        sign = sign->Next;
    Node<T>* p = new Node<T>;
    p->Data = data;
    p->Next = sign->Next;
    sign->Next = p;
}

//删除指定位置元素
template<class T>
void LinkList<T>::ele_delete(int posi)
{
    Node<T>* sign = Head;
    for(int i=1;i<posi;i++)
        sign = sign->Next;
    Node<T>* p = sign->Next;
    sign->Next = p->Next;
    delete p;
    p = nullptr;
}

//查询指定元素是否在链表中，若存在，返回第一个的位置，若不存在，返回-1
template<class T>
int LinkList<T>::ele_locate(T data)
{
    Node<T>* sign = Head->Next;
    int posi = 1;
    while(sign!=nullptr)
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
void LinkList<T>::ele_modify(int posi, T data)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
        sign = sign->Next;
    sign->Data = data;
}

//获取链表尾部元素
template<class T>
Node<T>* LinkList<T>::get_back()
{
    Node<T>* sign = Head;
    while(sign->Next!=nullptr)
        sign = sign->Next;
    return sign;
}

//移动到链表指定位置
template<class T>
Node<T>* LinkList<T>::move_to(int posi)
{
    Node<T>* sign = Head;
    for(int i=0;i<posi;i++)
        sign = sign->Next;
    return sign;
}