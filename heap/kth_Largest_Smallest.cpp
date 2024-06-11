#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>array={7,10,4,3,20,15};
    priority_queue <int> maxh;
    priority_queue <int,vector<int>,greater<int>> minh;
    int k=3;
    for(int i=0;i<array.size();i++)
    {
        maxh.push(array[i]);
        minh.push(array[i]);
        if(maxh.size() > k)
        {
            maxh.pop();
            minh.pop();
        }
    }
    cout<<"Third smallest number is:"<<maxh.top()<<endl;
    cout<<"Third largest number is:"<<minh.top()<<endl;
    return 0;
}
/*
OUTPUT

Third smallest number is:7
Third largest number is:10

*/
