#include<iostream>
#include<vector>
using namespace std;

//直接插入排序
vector<int> insertionSort(vector<int> array)
{
    for(int i=1;i<array.size();i++)
    {
        int temp = array[i];
        int k = i;
        while(k>0 && array[k-1]>temp)
        {
            array[k] = array[k-1];
            k--;
        }
        array[k] = temp;
    }
    return array;
}



void output(vector<int> array)
{
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[] = {3,2,1,4,0,5,7,9,6,8};
    vector<int> array(a,a+10);
    //vector<int> res = insertionSort(array);
    output(res);

    system("pause");
    return 0;
}