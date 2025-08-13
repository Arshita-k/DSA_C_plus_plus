#include <bits/stdc++.h>
using namespace std;

int Helper(vector<int>&arr)
{
    int n=arr.size();
    int prev1=arr[0], prev2=0; //intially there is no value for second previous
    for(int i=1;i<n;i++)
    {
        //pick the current element
        int pick=arr[i];
        if(i>1)
        {
            //if picking current element than we can only consider second previous elements
            pick+=prev2;
        }
        //if not considering current element we can consider just previous element from current
        int notPick=0+prev1;
        //store maximum value till now
        int curr=max(pick,notPick);
        
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int HouseRob(vector<int>& nums) 
{
        int n=nums.size();
        vector<int>arr1;
        vector<int>arr2;
        if(n==1)
        {
            return nums[0];
        }
        for(int i=0;i<n;i++)
        {
            if(i!=0) 
            {
                arr1.push_back(nums[i]);
            }
            if(i!=n-1)
            {
                arr2.push_back(nums[i]);
            }
        }
//using iterative appraoch otherwise will have to create to dp array to store
        int ans1=Helper(arr1);
        int ans2=Helper(arr2);

        return max(ans1,ans2);     
}

int main() {
    
    int n=4;
    vector<int>arr{1,2,3,1};
    cout<<HouseRob(arr);
    return 0;
}
        
           
