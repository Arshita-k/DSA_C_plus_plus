//Count number of subsequences with sum k using recursion
#include<bits/stdc++.h>
using namespace std;

int printS(int ind, vector<int>&ds, int s,int sum,int arr[],int n)
{
    //base case or termination case
    if(ind==n)
    {
        if(s==sum) return 1;
        else return 0;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    //Take elements
    int l=printS(ind+1,ds,s,sum,arr,n);
    //Backtrack
    s-=arr[ind];
    ds.pop_back();
    //Not take elements
    int r=printS(ind+1,ds,s,sum,arr,n);
    return l+r;
}
int main()
{
    int arr[]={1,2,1};
    int numofElements=3;
    int reqsum=2;
    vector<int>ds;
    cout<<printS(0,ds,0,reqsum,arr,numofElements);
    return 0;
}
