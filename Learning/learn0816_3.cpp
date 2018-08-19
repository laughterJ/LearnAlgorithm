#include<iostream>
using namespace std;

/*
    地图问题——dfs
    by 啊哈算法
*/

int cMap[6][6];
int sign[6];
int n,m;
int minPath;

void dfs(int cur, int dis)
{
    //优化
    if(dis>minPath)
        return;
    if(cur == n)
    {
        if(dis<minPath)
            minPath = dis;
        return;
    }
    step++;
    for(int i=1;i<=5;i++)
    {
        if(cMap[cur][i]>0 && sign[i] == 0)
        {
            //优化
            //dis+=cMap[cur][i];
            sign[i] = 1;
            dfs(i,dis+cMap[cur][i]);
            //dis -= cMap[cur][i];
            sign[i] = 0;
        }
    }

}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                cMap[i][j] = 0;
            else
                cMap[i][j] = -1;
        }
    }
    minPath = 0;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cMap[x][y] = z;
        minPath += z;
    }

    dfs(1,0);
    cout<<minPath<<endl;

    system("pause");
    return 0;
}