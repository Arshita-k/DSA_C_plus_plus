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
void find_middle(Node*& head)
{
    if(head==NULL)
    {
        cout<<"List is empty";
        return;
    }
    Node* fast=head;
    Node* slow=head;
    // first condition for even nodes 
    // next condition for odd number of nodes
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data;

}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next=node2;
    Node* node3 = new Node(3);
    node2->next=node3;
    Node* node4 = new Node(4);
    node3->next=node4;
    Node* node5 = new Node(5);
    node4->next=node5;
    find_middle(node1);
    return 0;
}
/*
    1     2     3     4     5 
 fast will take 2 steps
 slow will take 1 step at a time
 
 1st iteration
 fast will point to  3 element
 slow will point to  2 element

 2nd itertion 
 fast will move to 5 element
 slow will move to 3 element

 3rd iteration
 even condition && odd condition both needs to fullfill obviously agar abhi wali node ke aage kuch nhi hai toh uski aage wali ke aage bhi kuch nhi hoga
 fast == NULL && fast->next=NULL 
 reached at end
 slow will point to middle element // return it or print the middle element
*/
