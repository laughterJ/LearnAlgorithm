vector<int> adjustHeap(vector<int> array,int len)
{
    //len/2-1是当前序列第一个非叶子节点下标
    for(int i=len/2-1;i>=0;i--)
    {
        //找出左右孩子中较大的一个
        int maxChild = i*2+1;
        if(maxChild+1<len && array[maxChild]<array[maxChild+1])
            maxChild++;
        //比较左右孩子中较大的一个与父节点，比父节点大则交换
        if(array[maxChild]>array[i])
            swap(array[maxChild],array[i]);
    }
    return array;
}

vector<int> heapSort(vector<int> array)
{
    //每循环一次，将当前序列最大元素放在序列末尾
    //然后对未排序序列继续构造最大堆
    for(int i=array.size();i>0;i--)
    {
        //构造最大堆
        array = adjustHeap(array,i);
        //将堆顶与序列末尾元素交换
        swap(array[0],array[i-1]);
    }
    return array;
}

