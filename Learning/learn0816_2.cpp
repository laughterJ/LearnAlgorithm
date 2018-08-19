#include<iostream>
using namespace std;

/*
    图的遍历——广搜遍历
    by 啊哈算法
*/

int main()
{
    const int len = 100;
    int n,m;
    int e[len][len];
    int que[len*len+1],head,tail;
    int book[len+1];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                e[i][j] = 0;
            else
                e[i][j] = -1;
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a][b] = e[b][a] = 1;
    }

    head = 1;
    tail = 1;
    que[tail] = 1;
    tail++;
    book[1] = 1;
    while(head<tail)
    {
        int cur = que[head];
        for(int i=1;i<=n;i++)
        {
            if(e[cur][i] == 1 && book[i] == 0)
            {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
            if(tail>n)
                break;
        }
        head++;
    }
    for(int i=1;i<tail;i++)
        cout<<que[i]<<endl;

    system("pause");
    return 0;
}