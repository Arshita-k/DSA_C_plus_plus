#include <bits/stdc++.h>
using namespace std;

//length of longest substring
//variable size window k

void brute(string S)
{
    vector<int> chars(128,-1);
    int max_len=0;
    int start=-1;
    for(int i=0;i<S.size();i++)
    {
        if(chars[S[i]]>start)
        {
            start=chars[S[i]];
        }
        chars[S[i]]=i;
        max_len=max(max_len,i-start);
    }
    cout<<max_len;
}

int main()
{
    string str="practicemakesamanperfect";
    brute(str);
}
