#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
using namespace std;

template<class T>
class SeqList
{
    public:
        SeqList();
        SeqList(T *Data, int Size, int Length);
        virtual ~SeqList();
        T* get_data();
        T get_element(int loca);
        int get_length();
        void ele_delete(int loca);
        void ele_insert(int loca,T data);
        int ele_locate(T data);
        void sort_list();




    private:
        //数据集合
        T *Data;
        //当前顺序表中元素数量
        int Length;
        //顺序表容量
        int Size;

};

#endif // SEQLIST_H
