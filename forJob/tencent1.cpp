#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    vector<string> res;
    for(int i=0;i<t;i++)
    {
        int m;
        cin>>m;
        int n=m;
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        if(m%sum==0)
            res.push_back("Yes");
        else
            res.push_back("No");
    }

    for(int i=0;i<t;i++)
        cout<<res[i]<<endl;
    system("pause");
    return 0;
}