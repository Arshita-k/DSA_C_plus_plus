class Solution {
  public:
    void Helper(int ind,int sum,vector<int>&arr,vector<int>&ans,int n)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        //Pick
        Helper(ind+1,sum+arr[ind],arr,ans,n);
        //Not Pick
        Helper(ind+1,sum,arr,ans,n);
    }
    vector<int> subsetSums(vector<int>& arr) {
        
        int n=arr.size();
        vector<int>ans;
        Helper(0,0,arr,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
