#include<iostream>
using namespace std;

int main()
{
    int n,m;
    int N[100001];

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
        int l = 1,r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(N[mid]>num)
                r = mid;
            else if(N[mid]<num)
                l = mid+1;
            else
                break;
        }
        
        while(N[l]<num)
            l++;
        cout<<l<<endl;
    }

    system("pause");
    return 0;
}