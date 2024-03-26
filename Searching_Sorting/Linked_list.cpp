# include <bits/stdc++.h>
using namespace std;
//insert elements
//first element is already sorted becuase its a single element
//23 is sorted
//23 1 -> 1 23 swap
//1 23 10 -> 1 10 23 swap
//1 10 23 5 -> 1 5 10 23 swap

int Insertion_Sort(int arr[],int size)
{
    int i,key,j;
    for(i=1;i<size;i++)
    {
        key=arr[i];
        j=i-1;
    }
    //move elements of arr[0,i-1] that are greater than key 
    //to one position ahead of their current position

    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=key;
}
int main()
{
    int arr[]={23,1,10,5,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    Insertion_Sort(arr,size);
    return 0;
}
