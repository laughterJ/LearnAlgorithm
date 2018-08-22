#include<iostream>
using namespace std;

/*
    单源最短路径问题
    Dijkstra 算法
    by 啊哈算法
*/

int main()
{
    int cMap[100][100];
    int dis[100];
    int sign[100];
    int inf = 0;

    int cityNum,pathNum;
    cin>>cityNum>>pathNum;
    //初始化二维数组
    for(int i=1;i<=cityNum;i++)
    {
        for(int j=1;j<=cityNum;j++)
        {
            if(i==j)
                cMap[i][j] = 0;
            else
                cMap[i][j] = -1;
        }
    }
    //初始化路径
    for(int i=1;i<=pathNum;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cMap[a][b] = c;
        if(inf<c)
            inf = c;
    }
    //dis数组记录1号顶点到其余顶点的最短路程
    //sign数组标记顶点最短路径是否已找到
    for(int i=1;i<=cityNum;i++)
    {
        dis[i] = cMap[1][i];
        sign[i] = 0;
    }

    sign[1] = 1;
    int min,index;
    /*
    *   Dijkstra 算法核心部分
    *   依次找出离每个顶点最近的点，以这个点为中心，找出1号顶点过这个点
    *   到其余顶点的最小距离。
    */
    for(int i=1;i<=cityNum-1;i++)
    {
        //将min置为最大值
        min = inf;
        //依次遍历每个顶点，找出到顶点 i 路径最短的顶点 index，并将min置为最小值
        for(int j=1;j<=cityNum;j++)
        {
            if(sign[j]==0 && dis[j]<min && dis[j]!=-1)
            {
                min = dis[j];
                index = j;
            }
        }
        //将顶点 index 标记为已确定最短路径
        sign[index] = 1;
        //依次遍历每个顶点，找出 1 号顶点过顶点 index 到其余各点的最短距离
        for(int k=1;k<=cityNum;k++)
        {
            if(cMap[index][k]!=-1)
            {
                if(dis[k]>dis[index]+cMap[index][k]||dis[k]==-1)
                    dis[k] = dis[index]+cMap[index][k];
            }
        }
    }

    for(int i=1;i<=cityNum;i++)
        cout<<dis[i]<<" ";
    cout<<endl;

    system("pause");
    return 0;
}