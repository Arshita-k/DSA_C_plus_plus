// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void PrevGreater(vector<int>&arr, int n)
{
    stack<int>st;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty()) 
            cout<<-1<<endl;
        else
            cout<<st.top()<<endl;
        st.push(arr[i]);
    }
}
int main() {
    vector<int>arr{10,4,2,20,40,12,30};
    int n=arr.size();
    PrevGreater(arr,n);
    return 0;
}
