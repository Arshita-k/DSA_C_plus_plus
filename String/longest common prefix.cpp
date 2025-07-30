#include <bits/stdc++.h>
using namespace std;
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
int main()
{
    vector<string>strs = {"flower","flow","flight"};
    int first=strs[0].size();
    int arraylen=strs.size();
    string res;
    bool found=false;
    for(int i=0;i<first;i++)
    {
        char curr=strs[0][i];
        for(int j=1;j<arraylen;j++)
        {
            if(i==strs[j].size() || strs[j][i]!=curr)
            {
                res+=strs[0].substr(0,i);
                found=true;
                break;
            }
        }
        if(found) break;
    }
    cout<<res;
    return 0;
}
