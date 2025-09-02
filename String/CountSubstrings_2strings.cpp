// Count substrings of one string present in another
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int countSubstringWithHashing(string& s1, string& s2)
{
    unordered_set<string>substrings;
    int count=0;
    int n=s1.length();
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cout<<s1.substr(i,j-i)<<" "; //(position,number of elements)
            substrings.insert(s1.substr(i,j-i));
        }
    }
    for(auto& substring : substrings)
    {
        if(s2.find(substring)!=string::npos)
        {
            count++;
        }
    }
    return count;
}
int main() {
    
    string s1="abc";
    string s2="ababc";
    
    cout<<countSubstringWithHashing(s1,s2);
    return 0;
}
