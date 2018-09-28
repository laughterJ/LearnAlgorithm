//选择排序
vector<int> selectionSort(vector<int> array)
{
    for(int i=0;i<array.size();i++)
    {
        int min = i;
        for(int j=i+1;j<array.size();j++)
        {
            if(array[min]>array[j])
                min = j;
        }
        swap(array[min],array[i]);
    }
    return array;
}

//冒泡排序
vector<int> bubbleSort(vector<int> array)
{
    bool isSorted;
    for(int i=array.size()-1;i>0 && (!isSorted);i--)
    {
        isSorted = true;
        for(int j=0;j<i;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
                isSorted = false;
            }
        }
    }
    return array;
}

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

//希尔排序(变步长插入排序)
vector<int> shellSort(vector<int> array)
{
    int gap = array.size()/2;
    while(gap>=1)
    {
        for(int i=gap;i<array.size();i++)
        {
            int temp = array[i];
            int k = i;
            while(k>=gap && array[k-gap]>temp)
            {
                array[k] = array[k-gap];
                k-=gap;
            }
            array[k] = temp;
        }
        gap/=2;
    }
    return array;
}