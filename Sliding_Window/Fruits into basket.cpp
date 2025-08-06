// Fruits into basket
//Example 1:
// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
#include <bits/stdc++.h>
using namespace std;

int MaxFruits(vector<int>arr)
{
    int res=0;
    int n=arr.size();
    unordered_map<int,int>hashmap;
    int left=0,right=0;
    while(right<n)
    {
        while(hashmap.size()>2)
        {
            hashmap[arr[left]]--;
            //count--;
            if(hashmap[arr[left]]==0)
            {
                hashmap.erase(arr[left]);
            }
            left++;
        }
        hashmap[arr[right]]++;
        //count++;
        if(hashmap.size()<=2)
        {
            res=max(res,right-left+1);
        }
        right++;
    }
    return res;
}
int main() {
   vector<int>fruits={1,2,3,2,2};
   cout<<MaxFruits(fruits);
    return 0;
}
