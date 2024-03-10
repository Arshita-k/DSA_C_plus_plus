# include <bits/stdc++.h>
using namespace std;
//monotonic nature of array is necessary i.e. array is sorted
int binarySearch(int arr[],int l,int r,int value)
{
    int mid=l+(r-1)/2; //if l+r there can be segmentation fault (out of bound)
    if(arr[mid]==value) // T(n) = k+ T(n/2) = O(nlogn) time complexity
    {
        return mid;
    }
    if(arr[mid]<value)
    {
        l=mid+1;
    }
    else
    {
        r=mid-1;
    }
    return-1;

}
int main()
{
    int arr[]={2,3,4,10,40};
    int value=5;
    int size=sizeof(arr)/sizeof(arr[0]);
    int result=binarySearch(arr,0,size-1,value);
    (result == -1)
        ? cout <<"Element is not present in array"
        : cout <<"Element is present at index "<<result;
    return 0;
}
