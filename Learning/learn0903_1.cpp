#include <iostream>
#include "LinkList.cpp"
using namespace std;

/*
*   魔术师发牌问题
*       问题描述：魔术师利用一副牌中的13张黑牌，预先排好顺序后叠在一起，牌面朝下。
*   对观众说：“我不看牌，只数数就可以猜到每张牌是什么。”遂现场演示，魔术师将最上面
*   那张牌数为1，把他翻过来正好是黑桃A，将黑桃A放在桌子上，第二次数1,2，将第一张
*   牌放到最下面，翻开第二张牌，刚好是黑桃2，依次类推......
*       问题：求牌的最初顺序（自上而下）；
*/

int main()
{
    int a[13] = {0};
    LinkList<int> card(a,13);
    //将单链表连接成循环链表
    Node<int>* head = card.get_head();
    Node<int>* rear = card.get_back();
    rear->Next = head->Next;

    for(int i=1;i<=13;i++)
    {
        int k = 0;
        Node<int>* p = head;
        while(k<i)
        {
            p = p->Next;
            if(p->Data ==0)
                k++;
        }
        p->Data = i;
    }

    Node<int>* p = head->Next;
    for(int i=0;i<13;i++)
    {
        switch(p->Data){
            case 1:
                cout<<"A ";
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                cout<<p->Data<<" ";
                break;
            case 11:
                cout<<"J ";
                break;
            case 12:
                cout<<"Q ";
                break;
            case 13:
                cout<<"K ";
                break;
            default:
                break;
        }
        p = p->Next;
    }
    cout<<endl;

    system("pause");
    return 0;
}
