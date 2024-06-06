#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int arr[10]={1,1,2,3,3,3,4,5,1,6};
    int query_number=3;

    //precompute
    int hash[11] = {0};
    for(int i = 0; i < 10 ; i++)
    {
        hash[arr[i]] +=1;
    } 
    
    int number=0;
    while(query_number)
    {
        cout<<"Enter number : ";
        cin>>number;
        cout<<"frequency of "<< number <<" "<<hash[number]<<endl;
        query_number--;
    }
    return 0;
}
/*
OUTPUT
Enter number : 1
frequency of 1 3
Enter number : 9
frequency of 9 0
Enter number : 5
frequency of 5 1
OUTPUT
*/
