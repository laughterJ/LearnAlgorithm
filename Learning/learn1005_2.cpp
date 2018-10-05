#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<stack<int> > P;

void move(int n,int p1,int p2,int p3)
{
    if(n==1)
    {
        P[p3-1].push(P[p1-1].top());
        P[p1-1].pop();
        cout<<P[p3-1].top()<<": "<<"P"<<p1<<"-->"<<"P"<<p3<<endl;
    }
    else
    {
        //将n-1个圆盘从第p1根柱子移动到第p2根柱子
        move(n-1,p1,p3,p2);
        //将最底下的圆盘从第p1根柱子移动到第p3根柱子
        P[p3-1].push(P[p1-1].top());
        P[p1-1].pop();
        cout<<P[p3-1].top()<<": "<<"P"<<p1<<"-->"<<"P"<<p3<<endl;
        //将n-1个圆盘从第p2根柱子移动到第p3根柱子
        move(n-1,p2,p1,p3);
    }
}

int main()
{
    int n=4;
    for(int i=0;i<n;i++)
    {
        stack<int> p;
        P.push_back(p);
        //将n个圆盘由小到大记为1~n
        P[0].push(n-i);
    }
    move(n,1,2,3);
    getchar();
    return 0;
}