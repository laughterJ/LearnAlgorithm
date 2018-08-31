#include <iostream>
#include "src\SeqList.cpp"
using namespace std;

int main()
{
    int a[10] = {2,4,3,4,5};
    SeqList<int> cList(a,5,5);

    return 0;
}
