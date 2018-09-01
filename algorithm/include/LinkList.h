#ifndef LINKLIST_H
#define LINKLIST_H

template<class T>
struct Node{
    T Data;
    Node<T>* Next;
};

template<class T>
class LinkList
{
    public:
        LinkList();
        LinkList(T* data, int len);
        virtual ~LinkList();
        Node<T>* get_head();
        void ele_insert(T data, int posi);
        void ele_delete(int posi);
        int ele_locate(T data);
        void ele_modify(int posi, T data);
        Node<T>* get_back();
        Node<T>* move_to(int posi);

    private:
        Node<T>* Head;
};

#endif // LINKLIST_H
