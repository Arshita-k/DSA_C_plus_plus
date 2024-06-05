#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

int main()
{
    vector<int>array={1,2,3,4};
    Node* head= new Node(array[0]);
    Node* temp=head;
    //no need of while codition as firstly temp will point to first node
    for(int i=1;i<array.size();i++)
    {
        //yhn head ki baad wali intialised ho rahi hai
        temp->next=new Node(array[i]);
        //aur temp ko next node ko point karwa rahe hai
        temp=temp->next;
    }
    cout<<head->data;
    cout<<head->next->data;
    cout<<head->next->next->data;
    return 0;
}
