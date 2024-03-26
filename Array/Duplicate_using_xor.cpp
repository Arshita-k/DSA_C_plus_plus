#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int duplicate(vector<int> &arr)
{
    int ans=0;
  //XOR all array elements
    for(int i=0;i<arr.size();i++)
    {
        ans=ans^arr[i];
       // cout<<ans<<endl;
    }
  //xor [1 to n-1]
    for(int i=1;i<arr.size();i++)
    {
        ans=ans^i;
        //cout<<ans<<endl;
    }
    return ans;
}
int main() 
{
   vector<int>arr1={1,2,3,4,4};
   vector<int>arr2={4,2,1,3,1};
   int answer=duplicate(arr1);
   int answer1=duplicate(arr2);
   cout<<answer<<endl;
   cout<<answer1<<endl;
   return 0;
}
