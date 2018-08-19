#include<iostream>
using namespace std;
 
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x = (a+b)*c > a*(b+c) ? (a+b)*c : a*(b+c);
    int y = x > a*b*c ? x : a*b*c;
    cout<<y<<endl;
    system("pause");
    return 0;
}