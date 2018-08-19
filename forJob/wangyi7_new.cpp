#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<char> dic;

    while(n&&m)
    {
        long long num = 1;
        //计算 n-1个a 和 m个z 的全排列数量
        for(int i=1;i<n;i++)
        {
            num*=m+(n-i);
            num/=i;
            if(num>k)
                break;
        }
        //如果数量大于等于k，说明第k个是以a开头
        if(num>=k)
        {
            dic.push_back('a');
            n--;
        }
        //如果数量小于k，说明第k个是以z开头
        else
        {
            dic.push_back('z');
            m--;
            k-=num;
        }
    }
    //循环结束后，a或z必然有一个已经全部在字典中，所以只剩下一种情况
    if(k!=1)
    {
        cout<<-1<<endl;
        return 0;
    }

    while(n--)
        dic.push_back('a');
    while(m--)
        dic.push_back('z');

    for(int i=0;i<dic.size();i++)
        cout<<dic[i];
    cout<<endl;
    system("pause");
    return 0;
}