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
    int i=0, j=n-1;
    while(i<j)
    {
        while(arr[i]==0)
        {
           i++;
        }
        while(arr[j]==1)
        {
           j--;
        }
        if((arr[i]==1 && arr[j]==0 && i<j ))
        {
                   
            swap(arr[i],arr[j]);
             i++;
             j--;

        }
        
    }
}
int main() 
{
   int arr[6]={0,1,1,0,0,1};
   sort_0_1(arr,6);
   print_array(arr,6);
   return 0;
}
