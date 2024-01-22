#include <iostream>
using namespace std;
//iteration
void reverse(int arr[],int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
//recursive
void rreverse(int arr[],int n)
{
    int start=0;
    int end=n-1;
    if(start>=end)
      return;
    else
      int temp=arr[start];
      arr[start]=arr[end];
      arr[end]=temp;
    rreverse(arr,start+1,end-1)
}


void printArray(int arr[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]); 
    reverse(arr,n);
    rreverse(arr,n);
    printArray(arr,n);
    return 0;
}
