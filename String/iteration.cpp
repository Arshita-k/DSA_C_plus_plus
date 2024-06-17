#include <bits/stdc++.h>
using namespace std;
//iterator
int main()
{
    string str="practice makes a man perfect";
    cout<<"string is : "<<str<<endl;
    string::iterator it;
//begin() = This function returns an iterator to the beginning of the string.
//end() = returns an iterator to the next to the end of the string.
    for(it=str.begin();it!=str.end();it++)
    {
        if(*it=='m')
        {
            *it='M';
        }
        cout<<*it;
    }
    cout<<endl;
//rbegin() = returns a reverse iterator pointing at the end of the string    
//rend() = returns a reverse iterator pointing to the previous of beginning of the string.
    string::reverse_iterator rit;
    for(rit=str.rbegin();rit!=str.rend();rit++)
    {
        if(rit==str.rbegin())
        {
            *rit='T';
        }
        cout<<*rit;
    }
    cout<<endl;
//cbegin() = returns a constant iterator pointing to the beginning of the string, it cannot be used to modify the contents it points-to.
//cend() =  returns a constant iterator pointing to the next of end of the string, it cannot be used to modify the contents it points-to. 
//same for crbegin() and crend() but in reverse order
    for(auto cit=str.cbegin();cit!=str.cend();cit++)
    {
        //no modification allowed
        cout<<*cit;
    }
    cout<<endl;
    //normal iteration
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    return 0;
    //iteration with some pattern in reverse skipping 1 character
    for(int j=str.size()+1;j>=0;j=j-2)
    {
        cout<<str[j];
    }
    cout<<endl;
}
/* OUTPUT
string is : practice makes a man perfect
practice Makes a Man perfect
Tcefrep naM a sekaM ecitcarp
practice Makes a Man perfecT
practice Makes a Man perfecT
TerpnMaskMeicr
*/
