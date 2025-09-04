#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
#include <set>
using namespace std;

int lenOfDistinctSubstr(string& s)
{
    int n=s.length();
    string temp(s);
    set<string>answer;
    
    vector<int>freq(26,0);
    int maxx=INT_MIN;
    int left=0,right=0;
    
    while(right<=n)
    {
        if(freq[s[right]-'a']==0)
        {
            freq[s[right]-'a']=1;
            right++;
        }
        else
        {
            while(freq[s[right]-'a']==1)
            {
                freq[s[left]-'a']=0;
                left++;
            }
        }
        maxx=max(maxx,right-left);
        string is=temp.substr(left,maxx);
        answer.insert(is);
    }
    for(auto str : answer)
    {
        cout<<str<<" ";
    }
    cout<<endl;
    return maxx;
}
int main()
{
    string s="geeksforgeeks";
    cout<<lenOfDistinctSubstr(s);
}
