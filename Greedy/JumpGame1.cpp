class Solution {
public:
    bool canJump(vector<int>& arr) {

        int n=arr.size();
        if(arr[0]==0 && n>1) return false;
        
        int maxReach=0,currReach=0,jump=0;

        for(int i=0;i<n;i++)
        {
            maxReach=max(maxReach,i+arr[i]);
            if(maxReach>=n-1) return true;
            if(i==currReach)
            {
                if(i==maxReach) return false;
                else
                {
                    jump++;
                    currReach=maxReach;
                }
            }
        }
        return false;
    }
};
