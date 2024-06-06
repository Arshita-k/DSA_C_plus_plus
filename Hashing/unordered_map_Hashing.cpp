#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    string str="NNNNameeesSSpaccCCCCCe";
    int query_number=2;

    //precompute
    unordered_map<char,int>umap;
    for(int i = 0; i < str.size() ; i++)
    {
        umap[str[i]]++;
    }
    
    for(auto it : umap)
    {
        cout << it.first << "->" << it.second << endl;
        // it.first is key and it.second is value here frequency of the corresponding key
    }
    char ch;
    while(query_number)
    {
        cout<<"Enter character : ";
        cin>>ch;
        cout<<"frequency of "<< ch <<" "<<umap[ch]<<endl;
        query_number--;
    }
    return 0;
}
/*
OUTPUT

C->5
c->2
p->1
s->1
e->4
S->2
m->1
a->2
N->4
Enter character : N
frequency of N 4
Enter character : z
frequency of z 0

*/
