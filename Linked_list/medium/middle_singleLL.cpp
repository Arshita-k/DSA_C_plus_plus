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
    Node* temp=head;
    int count=0;
    while(temp!=NULL) //traverse till end
    {
        temp=temp->next;
        count++;
    }
    int middle_pos=(count/2 + 1); //if even = 4  (2+1=3 node)   if odd = 5 (2.5 +1 = 3.5 = 3 node ) //integer data type
    Node* temp1=head;
    int i=1;
    while(i<middle_pos)
    {
        temp1=temp1->next;
        i++;
    }
    cout<<temp1->data;
  //FOR LOOP SOLUTION
    // Node* temp1=head;
    // for(int i=1;i<middle_pos;i++)
    // {
    //     temp1=temp1->next;
    // }
    // cout<<temp1->data;
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
    //Node* node2 = new Node(5);
    //node4->next=node5;
}
