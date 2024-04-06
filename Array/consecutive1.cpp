#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    vector<int>arr;
    while(n>0)
    {
        int rem=n%2;
        n=int(n/2);
        arr.push_back(rem); 
    }
   //reverse(arr.begin(),arr.end()); 
    int count=0;
    int result=0;
    // 35 = 100011 
    for(int i=0;i<arr.size();i++)
    {
        //cout<<arr[i]<<endl;
        if(arr[i]==1)
        {
            count+=1;
            //cout<<count<<endl;
        }
        else
        {
            count=0;
            //cout<<count<<endl;
        }
        result=max(result,count); 
    }
    cout<<result; 
    return 0;
}
// dry run
/*  1st count=1   result=1
    2nd count=2   result=2
    3rd count=0   result=2
    4th count=0   result=2
    5th count=0   result=2
    6th count=1   result=2

*/
