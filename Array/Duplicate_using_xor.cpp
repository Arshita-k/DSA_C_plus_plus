#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int duplicate(vector<int> &arr)
{
    int maximum=*max_element(arr.begin(),arr.end());
    int minimum=*min_element(arr.begin(),arr.end());
    //cout<<maximum<<minimum;
    int ans=0,ans1=0;
  //XOR all integers from range min to max array elements
  // 1^2^3^4
    for(int i=minimum;i<=maximum;i++)
    {
        ans=ans^i;
    }
  //xor of all array elements 
 //1^2^3^4^4
    for(int i=0;i<arr.size();i++)
    {
        ans1=ans^arr[i];
        //cout<<ans<<endl;
    }
    // (1^2^3^4)^(1^2^3^4^4) = (1^1^2^2^3^3^4^4^4) = 0^4 = 4
    int result=ans^ans1;
    return result;
}
int main() 
{
    //array of element 1 to n-1 and one element is twice
   vector<int>arr1={1,2,3,4,4};
   //vector<int>arr2={4,2,1,3,1};
   int answer=duplicate(arr1);
   //int answer1=duplicate(arr2);
   cout<<answer<<endl;
  // cout<<answer1<<endl;
   return 0;
}
