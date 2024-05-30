//Monotonic Stack is used to maintain its elements in a specific order increasing or decreasing
//it is commohly used to efficiently solve problems such as finding the next greater or smaller element

#include<bits/stdc++.h>
using namespace std;

vector<int> monotonicInc(vector<int>n)
{
    stack<int>st;
    vector<int>answer;

    for(int i=0;i<n.size();i++)
    {
        while(!st.empty() && st.top() > n[i])
        {
            st.pop();
        }
        st.push(n[i]);
    }
    while(!st.empty())
    {
        //vector.insert(position,data_value)
        answer.insert(answer.begin(),st.top());
        st.pop();
    }
    return answer;

}
vector<int> monotonicDec(vector<int>n)
{
    stack<int>st;
    vector<int>answer;

    for(int i=0;i<n.size();i++)
    {
        while(!st.empty() && st.top() < n[i])
        {
            st.pop();
        }
        st.push(n[i]);
    }
    while(!st.empty())
    {
        //vector.insert(position,data_value)
        answer.insert(answer.begin(),st.top());
        st.pop();
    }
    return answer;

}

int main()
{
   vector<int> numbers={3,1,4,1,5,9,2,6};
   vector<int> results1 = monotonicInc(numbers);
   vector<int> results2 = monotonicDec(numbers);
   cout<<"Monotonic Increasing Stack : ";
   for(int i=0;i<results1.size();i++)
   {    
        cout<< results1[i] << " ";
   }
   cout<< endl;
   cout<<"Monotonic Decreasing Stack : ";
   for(int num:results2)
   {    
        cout<< num << " ";
   }
   cout<< endl;
   return 0;
}

/* 
OUTPUT
Monotonic Increasing Stack : 1 1 2 6 
Monotonic Decreasing Stack : 9 6 


A Monotonically Increasing Stack is a stack where elements are placed in increasing order from the bottom to the top. Each new element added to the stack
is greater than or equal to the one below it. If a new element is smaller, we remove elements from the top of the stack until we find one that is smaller 
or equal to the new element, or until the stack is empty. This ensures that the stack always stays in increasing order.

A Monotonically Decreasing Stack is a stack where elements are placed in decreasing order from the bottom to the top. Each new element added to the stack 
must be smaller than or equal to the one below it. If a new element is greater than top of stack then we remove elements from the top of the stack until 
we find one that is greater or equal to the new element, or until the stack is empty. This ensures that the stack always stays in decreasing order.

*/
