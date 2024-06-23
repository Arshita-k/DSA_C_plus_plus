#include <bits/stdc++.h>
using namespace std;

//longest subarray with sum
//variable size window k
int main()
{
    int arr[]={1,2,3,4,5};
    int max_length=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int window_sum=0;
    //generate all subarrays
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            //cout<<arr[j]<<" ";
            sum=sum+arr[j];
            if(sum<=6)
            {
                max_length=max(max_length,j-i+1);
            }
        }
        //cout<<endl;
    }
    cout<<max_length;
}
