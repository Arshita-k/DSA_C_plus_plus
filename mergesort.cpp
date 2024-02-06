#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
     while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++)
    {
        arr[i]=temp[i-low];
    }


}
//recurence function
void mergeSort(vector<int>&arr,int low,int high)
{
    //base condition if low=high 
    if(low>=high) 
    {
        return;
    }
    int mid=(low+high)/2;
    //recursive call to divide the array into halves
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    //to merge the  sorted halves 
    merge(arr,low,mid,high);
}
int main()
{
    vector<int> arr={9,2,4,1,7,5};
    int n=arr.size();
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
