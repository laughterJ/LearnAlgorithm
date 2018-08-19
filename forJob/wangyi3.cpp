#include<iostream>
#include<algorithm>
using namespace std;

int binSearch(int num)
{
    int i=1,j=n;
    while(j!=i)
    {
        int k = (i+j)/2;
        if(num>N[k])
        {
            if(j-i==1)
                return j;
            i = k;
        }
        else if(num<N[k])
        {
            if(j-1==1)
                return i;
            j = k;
        }
        else
            return k;
    }
    return i;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>N[i];
        N[i]+=N[i-1];
    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int num;
        cin>>num;
        cout<<binSearch(num)<<endl;
    }

    system("pause");
    return 0;
}