#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int num = 0;
    num+=1;
    num+=N;
    for(int i=N-2;i>=0;i--)
        num+=i+1;
    cout<<num<<endl;

    getchar();
    getchar();
    return 0;
}