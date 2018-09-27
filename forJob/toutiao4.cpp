#include<iostream>
using namespace std;

unsigned long long res = 0;
int num[3];

void dfs(int* sign,int cur)
{
    if(sign[0]==num[0]&&sign[1]==num[1]&&sign[2]==num[2])
    {
        res++;
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(sign[i]<num[i]&&i!=cur)
        {
            sign[i]++;
            dfs(sign,i);
            sign[i]--;
        }
    }
}

int main()
{
    
    
    cin>>num[0]>>num[1]>>num[2];
    for(int i=0;i<3;i++)
    {
        int sign[3] = {0};
        sign[i]++;
        dfs(sign,i);
    }
    cout<<res<<endl;
    system("pause");
    return 0;
}