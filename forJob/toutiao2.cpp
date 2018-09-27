#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> str;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        str.push_back(s);
    }
    vector<string> res;
    res.push_back(str[0].substr(0,1));
    for(int i=1;i<n;i++)
    {
        int k=1;
        for(int j=0;j<res.size();j++)
        {
            while(!str[i].substr(0,k).compare(res[j]))
            {
                k++;
                res[j] = str[j].substr(0,k);
            }
            if(k>1)
                break;
        }
        res.push_back(str[i].substr(0,k));
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<endl;
    system("pause");
    return 0;
}