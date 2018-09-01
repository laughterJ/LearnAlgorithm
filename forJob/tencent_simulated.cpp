#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> card;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        card.push_back(a);
    }
    sort(card.begin(),card.end());
    int sum = 0;
    int i;
    for(i=n-1;i>0;i-=2)
        sum+=card[i]-card[i-1];
    if(i==0)
        sum+=card[0];
    cout<<sum<<endl;
    system("pause");
    return 0;
}