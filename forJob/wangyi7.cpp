#include<iostream>
using namespace std;

int n,m,k;
char dic[201];
int sign[201];
int sum = 0;
bool flag = false;

void dfs(int num,int cur)
{
    if(num>=n)
    {
        sum++;
        if(sum==k)
            flag = true;
        return;
    }

    for(int i=cur+1;i<=m+n;i++)
    {
        dic[i] = 'a';
        dfs(num+1,i);
        if(flag)
            return;
        dic[i] = ' ';
    }
}

int main()
{
    cin>>n>>m>>k;
    dfs(0,0);
    if(flag)
    {
        for(int i=1;i<=m+n;i++)
        {
            if(dic[i]!='a')
                cout<<'z';
            else
                cout<<'a';
        }
        cout<<endl;
    }
    else
        cout<<-1<<endl;

    system("pause");
    return 0;
}