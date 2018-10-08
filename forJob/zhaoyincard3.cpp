#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    vector<int> weight;
    while(cin>>num)
        weight.push_back(num);
    sort(weight.begin(),weight.end()-1);
    int len = weight.size()-1;
    int limit = weight[len];
    int k = 0;
    num=0;
    for(int i=len-1;i>=k;i--)
    {
        if(weight[i]+weight[k]<=limit)
            k++;
        num++;
    }

    cout<<num<<endl;

    getchar();
    getchar();
    return 0;
}