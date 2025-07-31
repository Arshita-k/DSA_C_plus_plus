#include <bits/stdc++.h>
using namespace std;
// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once

string isAnagram(string s,string goal)
{
    if(s.length()!=goal.length()) return "No";
    unordered_set<char>sett(s.begin(),s.end());
    for(int i=0;i<goal.length();i++)
    {
        if(sett.find(goal[i])==sett.end())
            return "No";
    }
    return "Yes";
}
int main() {
    
    string s="abcde";
    string goal="bcdea";
    cout<<isAnagram(s,goal);
    cout<<endl;
    string s1="rat";
    string t ="car";
    cout<<isAnagram(s1,t);
    return 0;
}

//Another Solution
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length()!=t.length()) return false;
        int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0) return false;
        }
        return true;
        
    }
};
