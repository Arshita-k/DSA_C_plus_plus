#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    string str="nammeeeeespaaace";
    int query_number=3;

    //precompute
    int hash[26] = {0};
    for(int i = 0; i < str.size() ; i++)
    {
        hash[str[i] -'a'] +=1; //using ASCI VALUES 'a' = 97  [n-a] = [110 - 97]
        // same for upper case just has[s[i] - 'A'] using ASCI VALUES 'A' = 65 
    } 
    
    char ch;
    while(query_number)
    {
        cout<<"Enter character : ";
        cin>>ch;
        cout<<"frequency of "<< ch <<" : "<<hash[ch -'a']<<endl;
        query_number--;
    }
    return 0;
}
/*  OUTPUT

Enter character : n
frequency of n : 1
Enter character : a
frequency of a : 4
Enter character : z
frequency of z : 0

*/
