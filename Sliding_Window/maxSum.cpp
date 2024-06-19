#include <bits/stdc++.h>
using namespace std;

//maximum sum subarray of size k
//constant window with size k
int main()
{
    int arr[]={1,2,3,4,5};
    int k = 2,r=k-1,l=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxsum=0;
    for(int i=0;i<k;i++)
    {
        maxsum=maxsum+arr[i];
    }
    int windowSum=maxsum;
    while(r<n-1)
    { 
        windowSum=windowSum-arr[l];
        l++;
        r++;
        windowSum=windowSum+arr[r];
        maxsum=max(maxsum,windowSum);
    }
    cout<<"maximum sum is "<<maxsum;
    return 0;
}
/* OUTPUT 
maximum sum is 9
*/
