#include<iostream>
using namespace std;

/*
 * 递归求解八皇后问题
*/

int num = 0;

void EightQueen(int step,int chess[8][8])
{
    if(step==8)
    {
        num++;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int k=0;k<8;k++)
    {
        if(chess[step][k]==0)
        {
            bool flag = true;
            for(int i=0;i<8;i++)
            {
                if(chess[step][i]==1 || chess[i][k]==1)
                {
                    flag = false;
                    break;
                }
            }
            int i=step,j=k;
            while(i<8 && j<8 && flag)
                if(chess[i++][j++]==1)
                    flag = false;
            i=step,j=k;
            while(i<8 && j>=0 && flag)
                if(chess[i++][j--]==1)
                    flag = false;
            i=step,j=k;
            while(i>=0 && j<8&& flag)
                if(chess[i--][j++]==1)
                    flag = false;
            i=step,j=k;
            while(i>=0 && j>=0 && flag)
                if(chess[i--][j--]==1)
                    flag = false;
            if(flag)
            {
                chess[step][k] = 1;
                EightQueen(step+1,chess);
                chess[step][k] = 0;
            }
        }
    }
}

int main()
{
    int chess[8][8] = {0};
    EightQueen(0,chess);
    cout<<num<<endl;
    getchar();
    return 0;
}