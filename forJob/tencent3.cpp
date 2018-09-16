#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    string s;
    cin>>str>>s;

    long long int sum = 0;
    vector<int> loca;
    int len = s.length();
    for(int i=0;i<=str.length()-len;i++)
    {
        string cur = str.substr(i,len);
        if(s.compare(cur)==0)
            loca.push_back(i);
    }

    for(int i=0;i<loca.size();i++)
    {
        int start = loca[i];
        while(loca[i+1]-loca[i]<=len&&i+1<loca.size())
            i++;
        int end = loca[i]+len;
        sum+=(end-start)*(end-start);
    }
    cout<<sum<<endl;

    system("pause");
    return 0;
}