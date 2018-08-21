#include<iostream>
using namespace std;

/*
    多源最短路径问题
    Floyd-Warshall 算法
    by 啊哈算法
*/

int main()
{
    int cMap[100][100];
    int cityNum,pathNum;
    cin>>cityNum>>pathNum;

    //初始化二维矩阵
    for(int i=1;i<=pathNum;i++)
    {
        for(int j=1;j<=pathNum;j++)
        {
            if(i==j)
                cMap[i][j] = 0;
            else
                cMap[i][j] = -1;
        }
    }

    //初始化路径
    for(int i=0;i<pathNum;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cMap[a][b] = c;
    }

    //依次比较仅仅经过一个顶点时，路程是否缩短
    for(int k=1;k<=cityNum;k++)
    {
        for(int i=1;i<=cityNum;i++)
        {
            for(int j=1;j<=cityNum;j++)
            {
                if(cMap[i][k]>0 && cMap[k][j]>0)
                {
                    if(cMap[i][k] + cMap[k][j] < cMap[i][j] || cMap[i][j]<0)
                        cMap[i][j] = cMap[i][k]+cMap[k][j];
                }
            }
        }
    }

    for(int i=1;i<=cityNum;i++)
    {
        for(int j=1;j<=cityNum;j++)
            cout<<cMap[i][j]<<"\t";
        cout<<endl;
    }

    system("pause");
    return 0;
}