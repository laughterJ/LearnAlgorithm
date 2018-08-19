#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
    转机问题——bfs
    by 啊哈算法
*/

int main()
{
    queue<pair<int,int> > queCity;
    int cMap[100][100];
    int sign[100] = {0};
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
    
    int startCity,endCity;
    cin>>startCity>>endCity;
    //初始化城市间航班信息
    for(int i=1;i<=pathNum;i++)
    {
        int s,e;
        cin>>s>>e;
        cMap[s][e] = cMap[e][s] = 1;
    }

    //将起点城市入队
    queCity.push({startCity,0});
    //将起点城市标记为已经过
    sign[startCity] = 1;
    //若队列非空则循环
    while(!queCity.empty())
    {
        //依次遍历所有城市
        for(int i=1;i<=cityNum;i++)
        {
            //若当前城市到i城市有航班并且i城市未经过
            if(cMap[queCity.front().first][i]==1 && sign[i]==0)
            {
                将i城市入队，转机次数+1
                queCity.push({i,queCity.front().second+1});
                sign[i] = 1;
                if(i==endCity)
                {
                    cout<<queCity.back().second<<endl;
                    system("pause");
                    return 0;
                }
            }
        }
        //将当前城市出队
        queCity.pop();
    }

    system("pause");
    return 0;
}