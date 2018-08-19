#include<iostream>
using namespace std;

int n,k;
long long cur = 0;
long long cMax = 0;
int I[100000];
int S[100000];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>I[i];
    
    for(int i=0;i<n;i++)
    {
        cin>>S[i];
        if(S[i])
        {
            cur+=I[i];
            I[i] = 0;
        }
    }

    for(int i=0;i<k;i++)
        cur+=I[i];
    cMax = cur;

    for(int i=k;i<n;i++)
    {
        cur-=I[i-k];
        cur+=I[i];
        if(cur>cMax)
            cMax = cur;
    }

    cout<<cMax<<endl;
    system("pause"); 
    return 0;
}