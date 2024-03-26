//Reverse a string using recursion
#include <bits/stdc++.h>
using namespace std;

void reverse(string& S,int i, int j)
{
    cout<<" call recieved for "<< S <<endl;
    //base case
    if(i>j)
    {
        return;
    }
    swap(S[i],S[j]);
    i++;
    j--;
    reverse(S,i,j);
}
int main()
{
    string A="abcde";
    cout<<endl;
    int i=0;
    int j=A.length()-1;
    cout<<endl;
    reverse(A,i,j);
    cout<<A<<endl;
    return 0;
}
