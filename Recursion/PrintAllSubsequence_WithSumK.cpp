//Print all subsequence with sum k using recursion
#include<bits/stdc++.h>
using namespace std;

void printS(int ind, vector<int>&ds, int s,int sum,int arr[],int n)
{
    //base case or termination case
    if(ind==n)
    {
        if(s==sum)
        {
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    //Take elements
    printS(ind+1,ds,s,sum,arr,n);
    //Backtrack
    s-=arr[ind];
    ds.pop_back();
    //Not take elements
    printS(ind+1,ds,s,sum,arr,n);
    
    
}
int main()
{
    int arr[]={1,2,1};
    int numofElements=3;
    int reqsum=2; //K
    vector<int>ds;
    printS(0,ds,0,reqsum,arr,numofElements);
    return 0;
}
