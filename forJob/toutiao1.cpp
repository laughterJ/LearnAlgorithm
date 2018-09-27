#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string str;
    cin>>str;
    stack<string> sta;
    string res;
    for(int i=0;i<str.length();i++)
    {
		string name;
		while(i<str.length() && str[i]=='/')
				i++;
		while(i<str.length() && str[i]!='/')
			name += str[i++];
		if(name.compare(".") && name.compare(".."))
			sta.push(name);
		if(!sta.empty() && !name.compare(".."))
			sta.pop();
	}
	if(sta.empty())
	{
        cout<<"/"<<endl;
        return 0;
    }
	while(!sta.empty())
    {
		res = "/"+sta.top()+res;
		sta.pop();
	}
    cout<<res<<endl;
    return 0;
}