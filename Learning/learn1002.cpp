#include<iostream>
#include<vector>
using namespace std;


void output(vector<int> array)
{
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    vector<int> array{7,9,3,0,1,5,2,1,5,7};
    
    getchar();
    return 0;
}