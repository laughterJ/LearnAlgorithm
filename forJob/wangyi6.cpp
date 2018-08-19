#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int cMax=0,cMin=0;
int n,k;
vector<pair<int,int> > tower;
vector<pair<int,int> > trans;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        tower.push_back({temp,i});
    }
    sort(tower.begin(),tower.end());

    int i = k;
    while(i>0)
    {
        if(tower.front().first<tower.back().first)
        {
            tower.front().first++;
            tower.back().first--;
            trans.push_back({tower.front().second,tower.back().second});
            sort(tower.begin(),tower.end());
            i--;
        }
        else
            break;
    }

    cout<<tower.back().first-tower.front().first<<" "<<k-i<<endl;
    for(auto ele : trans)
        cout<<ele.second<<" "<<ele.first<<endl;
    system("pause");
    return 0;
}