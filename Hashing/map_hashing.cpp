#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int arr[20]={1,1,12,3,3,34,4,5,1,6,12,97,34,3,34,12,2,5,97};
    int query_number=2;

    //precompute
    map<int,int>mpp;
    for(int i = 0; i < 20 ; i++)
    {
        mpp[arr[i]]++;
    }
    
    for(auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
        // it.first is key and it.second is value here frequency of the corresponding key
    }
    int number=0;
    while(query_number)
    {
        cout<<"Enter number : ";
        cin>>number;
        cout<<"frequency of "<< number <<" "<<mpp[number]<<endl;
        query_number--;
    }
    return 0;
}
/* OUTPUT

0->1
1->3
2->1
3->3
4->1
5->2
6->1
12->3
34->3
97->2
Enter number : 11
frequency of 11 0
Enter number : 97
frequency of 97 2

*/
