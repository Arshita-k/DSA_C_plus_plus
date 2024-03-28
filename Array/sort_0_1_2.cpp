#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sort_0_1(int arr[],int n)
{
    int low=0,mid=0,high=n-1; //3 way partitioning
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]); //encountered 0 move it before low pointer // and increment mid and low pointer
            low++;
            mid++;
        }
        else if(arr[mid]==1) //ignore it is on correct place move mid pointer forward
        {
           mid++;
        }
        else // if mid find a 2 before a high pointer we need to move it after high pointer and decrement high pointer
        {
                   
            swap(arr[mid],arr[high]);    
            high--;

        }   
    }
}
int main() 
{
   int arr[8]={0,1,2,0,2,1,0,0};
   sort_0_1(arr,8);
   print_array(arr,8);  
   return 0;
}
