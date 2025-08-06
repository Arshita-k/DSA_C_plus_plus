// Given a string s, find the length of the longest substring without duplicate characters.
#include <bits/stdc++.h>
using namespace std;

int LongestSubstring(string s)
{
    int len=s.length()-1;
    unordered_set<char>hashset;
    int res=-1;
    //naive approach (track for each character of string)
    for(int i=0;i<=len;i++)
    {
        //start from s[i] to s[len-1]
        for(int j=i;j<=len;j++)
        {
            if(hashset.find(s[j])!=hashset.end())
            {
                hashset.clear();
                break;
                
            }
            else
            {
                res=max(res,j-i+1);
                hashset.insert(s[j]);
            }
        }
    }
    return res;
}

int LongestSubstringApp2(string s)
{
    int len=s.length()-1;
    int res=-1;
    //two ppointer
    int left=0,right=0;
    vector<int>vis(26,0);
    while(right<=len)
    {
        while(vis[s[right]-'a']==1)
        {
            vis[s[left]-'a']--;
            left++;
        }
        vis[s[right]-'a']++;
        res=max(res,(right-left+1));
        right++;
    }
    return res;
}
int main() {
    string s = "abcabcbb";
    string t = "pwwkew";
    string r=  "bbbbb";
    cout<<LongestSubstring(s)<<endl;
    cout<<LongestSubstringApp2(t);
    return 0;
}
