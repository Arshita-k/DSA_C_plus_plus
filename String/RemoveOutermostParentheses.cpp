#include <bits/stdc++.h>
using namespace std;
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
int main()
{
    string s = "(()())(())";
    int len=s.length();
    int openCount=0,closeCount=0,start=0;
    string result;
    for(int i=0;i<len;i++)
    {
        char ch=s[i];
        if(ch=='(') openCount++;
        if(ch==')') closeCount++;
        if(openCount==closeCount)
        {
            result+=s.substr(start+1,i-start-1);
            start=i+1;
        }
    }
    cout<<"String after removing outermost parenthesis: "<<result;
    return 0;
}
