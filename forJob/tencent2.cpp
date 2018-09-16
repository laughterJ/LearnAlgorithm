#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> array;
    int num=0;
    for(int i=0;i<N;i++)
    {
        int sign;
        cin>>sign;
        array.push_back(sign);
        if(sign)
            num++;
    }
    if(num==1)
    {
        cout<<1<<endl;
        return 0;
    }
    vector<int> res;
    for(int i=1;i<N;i++)
    {
        if(array[i]==0&&array[i-1]==1)
        {
            num = 0;
            while(array[i]==0)
            {
                num++;
                i++;
                if(i>=N)
                    break;
            }
            if(num>0&&i<N)
                res.push_back(num+1);
        }
    }

    int kand = 1;
    for(int i=0;i<res.size();i++)
        kand*=res[i];
    cout<<kand<<endl;
    system("pause");
    return 0;
}