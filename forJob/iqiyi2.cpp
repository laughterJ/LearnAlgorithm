#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Food{
    int first;
    int second;

    Food(int x,int y){
        first = x;
        second = y;
    }
};

bool cmp( const Food &v1, const Food &v2)
{  
    return v1.second > v2.second;
} 


int main()
{
    int N,M,P;
    cin>>N>>M>>P;
    vector<Food> foods;
    for(int i=1;i<=N;i++)
    {
        int num;
        cin>>num;
        Food food(i,num);
        foods.push_back(food);
    }
    for(int i=0;i<M;i++)
    {
        char c;
        cin>>c;
        int num;
        cin>>num;
        if(c=='A')
            foods[num-1].second++;
        else
            foods[num-1].second--;
    }
    sort(foods.begin(),foods.end(),cmp);
    if(foods[0].first==P)
    {
        cout<<1<<endl;
        return 0;
    }else
    {
        foods[0].first = 1;
    }
    for(int i=1;i<N;i++)
    {
        if(foods[i].first==P)
        {
            if(foods[i].second==foods[i-1].second)
                cout<<foods[i-1].first<<endl;
            else
                cout<<i+1<<endl;
            return 0;
        }
        else
        {
            if(foods[i].second==foods[i-1].second)
                foods[i].first = foods[i-1].first;
            else
                foods[i].first = i+1;
        }
    }

    system("pause");
    return 0;
}