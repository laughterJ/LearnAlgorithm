vector<int> mergeSort(vector<int> &array)
{
    sort(array,0,array.size()-1);
}

void sort(vector<int> &array,int left,int right)
{
    if(right>left)
    {
        int mid = (left+right)/2;
        sort(array,left,mid);
        sort(array,mid+1,right);
        merge(array,left,mid+1,right);
    }
}

void merge(vector<int> &array,int left,int mid,int right)
{
    vector<int> temp;
    int i=left,j=mid;
    while(i<mid && j<=right)
    {
        if(array[i]<array[j])
            temp.push_back(array[i++]);
        else
            temp.push_back(array[j++]);
    }
    while(i<mid)
        temp.push_back(array[i++]);
    while(j<=right)
        temp.push_back(array[j++]);
    int k = 0;
    while(left<=right)
        array[left++] = temp[k++];
}
