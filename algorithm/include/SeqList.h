#ifndef SEQLIST_H
#define SEQLIST_H

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
        void ele_insert(T data, int loca);
        void ele_delete(int loca);
        int ele_locate(T data);
        void ele_modify(T data, int loca);
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
