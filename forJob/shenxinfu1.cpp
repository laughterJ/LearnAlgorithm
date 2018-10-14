#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int> nums;
    int n;
    for(int i=0;i<num;i++)
    {
        cin>>n;
        nums.push_back(n);
    }
    sort(nums.begin(),nums.end());
    int center = nums[nums.size()/2];
    int num_add;
    cin>>num_add;
    for(int i=0;i<num_add;i++)
    {
        cin>>n;
        nums.push_back(n);
    }
    cout<<center<<endl;
    sort(nums.begin(),nums.end());
    cout<<nums[nums.size()/2]<<endl;

    getchar();
    getchar();
    return 0;
}