//HeapSort
#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int len,int ind)
{
    int large=ind;
    int left=2*ind+1;
    int right=2*ind+2;
    
    if(left<len && arr[left]>arr[large])
    {
        large=left;
    }
    if(right<len && arr[right]>arr[large])
    {
        large=right;
    }
    
    if(large!=ind)
    {
        swap(arr[ind],arr[large]);
        heapify(arr,len,large);
    }
}
void heapsort(vector<int>&arr)
{
    int len=arr.size();
    //create a max heap start from rightmost node but not a leaf node (leaf node does not have children so no need to check)
    for(int i=len/2-1;i>=0;i--)
    {
        //cout<<arr[i]; //3 4 9
        heapify(arr,len,i);
    }
    
    for(int i=len-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        //heapify from start but the size of computation is decreasing
        heapify(arr,i,0);
    }
}
int main() {
    
    vector<int>arr={9,4,3,8,10,2,5};
    heapsort(arr);
    cout<<"Sorted array is \n";
    for(auto num : arr)
    {
        cout<<num<<" ";
    }
    return 0;
}
