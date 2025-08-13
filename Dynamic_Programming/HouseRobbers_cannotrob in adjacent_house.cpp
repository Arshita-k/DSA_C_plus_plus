class Solution {
private:
    int Helper(int index,vector<int>&arr,vector<int>&dp)
    {
        if(index==0)
        {
            return arr[index];
        }
        if(index<0)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        //if picked current than skip next move 2 steps
        int pick=arr[index]+Helper(index-2,arr,dp);
        // if not picked current than no need skip next move 1 steps
        int nonPick=0+Helper(index-1,arr,dp);
        //store maximum value among them 
        return dp[index]=max(pick,nonPick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return Helper(n-1,nums,dp);
    }
};
