#include <bits/stdc++.h>
using namespace std;

//longest subarray with sum <=6
//variable size window k

void brute(vector<int>&arr,int S)
{
    int max_length=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    //generate all subarrays and do sum till u get required sum
    for(int i=0;i<n;i++)   //TC O(N^2)  SC O(1)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            //cout<<arr[j]<<" ";
            sum=sum+arr[j];
            if(sum<=S)
            {
                max_length=max(max_length,j-i+1);
            }
            else if(sum>6) break;
        }
        //cout<<endl;
    }
    cout<<max_length;
}
void better(vector<int>&arr,int S) //TC O(N+N)=O(2N) //SC=O(1)  
{
    int l=0;
    int r=0;
    int sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_length=0;
    while(r<n)
    {
        sum=sum+arr[r];
        while(sum>S)//shrink till window sum exceeds the condition
        {
            sum=sum-arr[l];
            l++;
        }
        if(sum<=S) //expand the window till the condition gets fulfilled
        {
            max_length=max(max_length,r-l+1);
        }
        r++;
    }
    cout<<max_length;

}
void optimise(vector<int>&arr,int S) //TC O(N)=O(N) //SC=O(1)  
{
    int l=0;
    int r=0;
    int sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_length=0;
    while(r<n)
    {
        sum=sum+arr[r];
        if(sum>S)//shrink only once if window sum exceeds the condition
        {
            sum=sum-arr[l];
            l++;
        }
        if(sum<=S) //expand the window till the condition gets fulfilled
        {
            max_length=max(max_length,r-l+1);
        }
        r++;
    }
    cout<<max_length;

}
int main()
{
    vector<int>arr={1,2,3,4,5,6};
    better(arr,6);
}
