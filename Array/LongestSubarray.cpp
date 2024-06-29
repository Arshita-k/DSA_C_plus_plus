#include <bits/stdc++.h>
using namespace std;
//brute force
int LongestSubarray(vector<int>&arr,long long S) //approx TC = O(n^3)
{
    int len=0;
    for(int i=0 ; i<arr.size() ; i++)
    {
        for(int j=i ; j<arr.size() ; j++)
        {
            long long sum=0;
            for(int k=i ; k<=j ; k++)
            {
                sum+=arr[k];
            }
            if(sum==S)
            {
                len=max(len,j-i+1);
            }

        }
    }
    return len;
}
//more optimised
int LongestSubarray1(vector<int>&arr,long long S) //approx TC = O(n^2)
{
    int len=0;
    for(int i=0 ; i<arr.size() ; i++)
    {
        long long sum=0;
        for(int j=i ; j<arr.size() ; j++)
        {
            sum+=arr[j];
            if(sum==S)
            {
                len=max(len,j-i+1);
            }
            if(sum>S)
            {
                break;
            }

        }
    }
    return len;
}
int LongestSubarray3(vector<int>&arr,long long S) //O(2N) in worst case 
{
    int n=arr.size();
    int i=0,j=0;
    long long sum=arr[0];
    int maxlen=0;
    while(j<n)
    {
        if(sum == S)
        {
            maxlen=max(maxlen,j-i+1);
        }
        j++;
        if(j<n)
        {
            sum+=arr[j];
        }
        while(i <= j && sum > S)
        {
            sum-=arr[i];
            i++;
        }
    }
    return maxlen;
}
int LongestSubarray4(vector<int>&arr,long long S) //approx TC = O(n) or O(nlogn)
{
    int n=arr.size();
    map<long long,int> preSumMap;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum==S)
        {
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-S;
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int len=i-preSumMap[rem];
            maxlen=max(maxlen,len);
        }
        if(preSumMap.find(rem)==preSumMap.end())
        {
            preSumMap[sum]=i;
        } 
    }
    return maxlen;
}
int main()
{
    vector<int>arr = {1,2,3,4};
    long long S = 3;
    int length = LongestSubarray4(arr,S);
    cout<<"The length of the longest subarray is: "<<length<<endl;
    return 0;
}
