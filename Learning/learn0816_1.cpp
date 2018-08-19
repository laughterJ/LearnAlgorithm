#include<iostream>
using namespace std;

/*
    图的遍历——深搜遍历
    by 啊哈算法
*/

const int len = 101;
int e[len][len],book[101];
int sum,n,m;

void dfs(int cur)
{
    cout<<cur<<endl;
    sum++;
    if(sum == n)
        return;
    for(int i=1;i<=n;i++)
    {
        if(e[cur][i] == 1 && book[i] == 0)
        {
            book[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    cin>>n;
    sum = 0;
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
    book[1] = 1;
    dfs(1);

    system("pause");
    return 0;
}