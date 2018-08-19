#include<iostream>
using namespace std;

int N[1001] = {0};

int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        N[x]++;
    }
    int score = N[1];
    for(int i=2;i<=n;i++)
    {
        if(N[i]<score)
            score = N[i];
    }
    cout<<score<<endl;
    system("pause");
    return 0;
}