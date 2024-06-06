#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    string str="NammeeeeeSSSpaaaCCe";
    int query_number=3;

    //precompute
    int hash[256] = {0};
    for(int i = 0; i < str.size() ; i++)
    {
        hash[str[i]] +=1; //using ASCI VALUES 'a' = 97 and 'A' = 65
        //we have total 256 ASCII characters use hash[256] when not specified about string
    } 
    
    char ch;
    while(query_number)
    {
        cout<<"Enter character : ";
        cin>>ch;
        cout<<"frequency of "<< ch <<" : "<<hash[ch]<<endl;
        query_number--;
    }
    return 0;
}
/* 
OUTPUT
Enter character : N
frequency of N : 1
Enter character : A S
frequency of S : 3
Enter character : e
frequency of e : 6
*/
