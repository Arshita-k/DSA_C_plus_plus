#include <bits/stdc++.h>
using namespace std;

//best case O(1) 
//average case O(logn)
//worst case O(logn)
int BinarySearch(vector<int>&arr,int target)
{
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[start]==target)
        {
            cout<<arr[start]<<" == "<<target<<endl;
            return start;
        }
        else if(arr[end]==target)
        {
            cout<<arr[end]<<" == "<<target<<endl;
            return end;
        }
        if(arr[mid]==target)
        {
            cout<<arr[mid]<<" == "<<target<<endl;
            return mid;
        }
        else if(arr[mid]<target)
        {
            cout<<arr[mid]<<" < "<<target<<endl;
            start=mid+1;
        }
        else
        {
            cout<<arr[mid]<<" > "<<target<<endl;
            end=mid-1;

        }
    }
    return 0;
}
int main()
{
    vector<int>arr={2,5,8,12,16,23,38,56,72,91};
    int result=0;
    result=BinarySearch(arr,2);
    return 0;
}
