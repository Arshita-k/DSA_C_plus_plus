#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> pair_sum(vector<int> &arr,int key)
{
   int n=arr.size();
   vector<vector<int>>answer;
   for(int i=0;i<n;i++)
   {
       for(int j=i+1;j<n;j++)
       {
          if(arr[i]+arr[j]==key)
          {
            vector<int>temp;
            temp.push_back(min(arr[i],arr[j]));
            temp.push_back(max(arr[i],arr[j]));
            answer.push_back(temp);
          }
       }
   }
   sort(answer.begin(),answer.end());
   return answer;   
}
int main() 
{
   vector<int>arr={1,2,3,4,4};
   int key=5;
   vector<vector<int>>result;
   result=pair_sum(arr,key);
   return 0;
}
