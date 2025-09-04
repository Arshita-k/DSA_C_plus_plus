#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int CountMaxConsecutive(string& s)
{
    int n=s.length();
    int count=1;
    int maxx=INT_MIN;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            maxx=max(maxx,count);
            count=1;
        }
        else
        {
            count++;
        }
    }
    return maxx;
}
int main()
{
    string s="geeeeksforgeeks";
    cout<<CountMaxConsecutive(s);
}
