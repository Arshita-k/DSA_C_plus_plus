#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>nums)
{
    int size=nums.size();
    int count=0;
    for(int i=1;i<size;i++)
    {
        if(nums[i-1]>nums[i])
        {
            count++;
        }
    }
    if(nums[size-1]>nums[0])
    {
        count++;
    }
    // only one condition if(nums[i]>nums[i+1]%nums.size())

    //check if the array has less than or only one breakpoint otherwise array is not sorted or rotated 
    return count<=1;

}
int main()
{
    vector<int>arr={3,4,5,1,2};  //returns true  5>1
    vector<int>arr1={2,1,3,4};   //2>1  and 4>2 two breakpoints returns false
    cout<<check(arr1);
}   
