//Print any one subsequence with sum k using recursion
#include<bits/stdc++.h>
using namespace std;

bool printS(int ind, vector<int>&ds, int s,int sum,int arr[],int n)
{
    //base case or termination case
    if(ind==n)
    {
        if(s==sum)
        {
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    //Take elements
    if(printS(ind+1,ds,s,sum,arr,n)==true)
    {
        return true;
    }
    //Backtrack
    s-=arr[ind];
    ds.pop_back();
    //Not take elements
    if((printS(ind+1,ds,s,sum,arr,n)==true))
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[]={1,2,1};
    int numofElements=3;
    int reqsum=2;
    vector<int>ds;
    printS(0,ds,0,reqsum,arr,numofElements);
    return 0;
}
