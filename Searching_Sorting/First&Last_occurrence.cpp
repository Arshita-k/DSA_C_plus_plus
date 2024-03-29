# include <bits/stdc++.h>
using namespace std;
//given an sorted array we need to find first and last occurrence of a key value 
//can be solved using binary search
int first_occurence(int arr[],int size,int value)
{
    int l=0,r=size-1;
    int first= -1;
    int mid=l+(r-l)/2; 
    while(l<=r)
    {
        if(arr[mid]==value) 
        {
            first=mid; //to store first occurence of mid
            r=mid-1; //check if the same key value exists in left side of mid if we find mid==key so we update end here 
          //i.e value=3  1,2,3,3,4,5,6  here mid=3 but at index=2 lies the first occurrence so we need to check left side of mid
        }
        else if(arr[mid]<value){l=mid+1;}
        else if(arr[mid]>value){r=mid-1;}
        mid=l+(r-l)/2;
    }
    return first;
}   
int last_occurence(int arr[],int size,int value)
{
    int l=0,r=size-1;
    int last=-1;
    int mid=l+(r-l)/2; 
    while(l<=r)
    {
        if(arr[mid]==value) 
        {
            last=mid; //same case here store last occurence but we need to check if at right side the value exist or not so we update start here
            l=mid+1;
        }
        else if(arr[mid]<value){l=mid+1;}
        else if(arr[mid]>value){r=mid-1;}
        mid=l+(r-l)/2;
    }
    return last;
}
int main()
{
    int arr[]={2,3,4,10,10,10};
    int value=10;
    int size=sizeof(arr)/sizeof(arr[0]);                        
    int result1=first_occurence(arr,size,value);
    int result2=last_occurence(arr,size,value);
    (result1 == -1)
        ? cout <<"Element is not present in array"
        : cout <<"First occurrence of element is present at index "<<result1<<endl
            <<"Last occurrence of element is present at index "<<result2<<endl;
    return 0;
}
