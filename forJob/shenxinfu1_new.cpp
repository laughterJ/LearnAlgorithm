#include<iostream>
#include<vector>
using namespace std;

bool flag = false;
int center = 0;

void searchMedian(vector<int> array,int left,int right)
{
    if(left>=right || flag == true)
        return;
    int sign = array[left];
    int i = left+1,j = right;
    while(i<j)
    {
        while(array[j]>sign && i<=j)
            j--;
        while(array[i]<sign && i<=j)
            i++;
        if(i<j)
            swap(array[i],array[j]);
    }
    swap(array[left],array[j]);
    if(j==array.size()/2)
    {
        flag = true;
        center = array[j];
        return;
    }
    searchMedian(array,left,j-1);
    searchMedian(array,j+1,right);
}

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
    flag = false;
    searchMedian(nums,0,nums.size()-1);
    cout<<center<<endl;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>n;
        nums.push_back(n);
    }
    flag = false;
    searchMedian(nums,0,nums.size()-1);
    cout<<center<<endl;

    getchar();
    getchar();
    return 0;
}