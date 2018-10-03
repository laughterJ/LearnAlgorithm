void quickSort(vector<int> &array){
    //对数组第一个到最后一个元素进行快排
    sort(array,0,array.size()-1);
}

void sort(vector<int> &array,int left,int right){
    if(left>right)
        return;
    int i=left,j=right;
    //取待排序序列最后一个元素为基准数
    int sign = array[right];
    while(i<j){
        //从前往后找比基准数大的数
        while(array[i]<=sign && i<j)
            i++;
        //从后往前找比基准数小的数
        while(array[j]>=sign && i<j)
            j--;
        //只有比基准数大的数在比基准数小的数前面时才需要交换
        if(i<j)
            swap(array[i],array[j]);
        else
            break;
    }
    //将基准数归位
    if(i != right){
        swap(array[i],array[right]);
    }
    //对基准数左边的序列快排
    sort(array,left,i-1);
    //对基准数右边的序列快排
    sort(array,i+1,right);
}