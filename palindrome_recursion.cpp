#include <bits/stdc++.h>
using namespace std;
//palindrome if original string and reverse string is equal
//aabbaa 
bool checkPalindrome(string S,int i,int j)
{
    if(i>j)
    {
        return true;
    }
    if(S[i]!=S[j])
    {
        return false;  
    }
    else
    {
         return checkPalindrome(S,i+1,j-1);
    }
}
int main()
{
    string A="aabbaa";
    int i=0;
    int j=A.length()-1;
    bool isPalindrome=checkPalindrome(A,i,j);
    if(isPalindrome)
    {
        cout<<"It's a palindrome"<<endl;
    }
    else
    {
        cout<<"It's not palindrome"<<endl;
    }
    return 0;
}

