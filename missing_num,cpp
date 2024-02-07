#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//linear search
int missing_num1(vector<int>arr,int size)
{
    for(int i=1;i<=size;i++)
    {
        int flag=0;
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return i;
        }
    }
    return -1;
}
//hashing
int missing_num2(vector<int>arr,int size)
{
    //size+1 because we will store frequency 0 of missing number also
    int hash[size+1]={0};
    for(int i=0;i<=size-1;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=1;i<=size;i++)
    {
        if(hash[i]==0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={1,2,4,5,6};
    int n=arr.size();
    int ans1=missing_num1(arr,n);
    int ans2=missing_num2(arr,n);
    cout<<"Missing number from 1st: "<<ans1<<endl;
    cout<<"Missing number from 2nd: "<<ans2<<endl;
    return 0;
}
