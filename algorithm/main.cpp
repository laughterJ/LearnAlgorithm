#include <iostream>
#include "src\SeqList.cpp"
using namespace std;

int main()
{
    int a[10] = {2,4,3,4,5};
    SeqList<int> cList(a,5,5);
    int* data = cList.get_data();
    for(int i=1;i<=cList.get_length();i++)
        cout<<data[i]<<" ";
    cout<<endl;

    cList.ele_insert(2,6);
    cList.ele_delete(1);
    data = cList.get_data();
    for(int i=1;i<=cList.get_length();i++)
        cout<<data[i]<<" ";
    cout<<endl;

    cList.ele_insert(1,1);
    cList.ele_insert(2,2);
    cList.sort_list();
    data = cList.get_data();
    for(int i=1;i<=cList.get_length();i++)
        cout<<data[i]<<" ";
    cout<<endl;

    return 0;
}
