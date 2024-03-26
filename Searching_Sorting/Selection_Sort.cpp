# include <bits/stdc++.h>
using namespace std;
//monotonic nature of array is necessary i.e. array is sorted
int Selection_Sort(int arr[],int size)
{
    int i,j,min_idx;
    for(int i=0;i<size-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx!=i)
        {
            swap(arr[min_idx],arr[i]);
        }
    }
}
int main()
{
    int arr[]={40,2,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    Selection_Sort(arr,size);
    return 0;
}
