#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "the sky is blue";
    //reverse(s.begin(),s.end()); not correct
    string word,res;
    stringstream ss(s);
    stack<string>st;
    while(ss>>word)
    {
        st.push(word);
    }
    while(st.empty()==0)
    {
        res+=st.top();
        res+=" ";
        st.pop();
    }
    cout<<res;
    return 0;
}
