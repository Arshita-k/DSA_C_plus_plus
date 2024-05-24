#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;
};
void insertAtBeg(Node*& head,int value)
{
    Node* newnode=new Node();
    newnode->data=value;
    newnode->prev=NULL; //it will be first node so previous will point to NULL
    if(head==NULL) //if list is empty
    {
        newnode->next=NULL; //no current node available hence next will point to NULL
        head=newnode;
    }
    else
    {
        newnode->next=head; //newnode next will point to current first node
        head->prev=newnode; //current node previous will point to newnode
        head=newnode; //head will point to new node
    }

}
void insertAtEnd(Node*& head,int value)
{
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=NULL; //it will be last node so next will point to NULL
    if(head==NULL) //if list is empty
    {
        newnode->prev=NULL; //no current node available hence next will point to NULL
        head=newnode;
    }
    else
    {
        Node* current=head;
        while(current->next!=NULL) //traverse 
        {
            current=current->next;
        }
        current->next=newnode; //current node will point to new node
        newnode->prev=current; //newnode previous will point to current node
    }
}
void insertAtPosition(Node*& head,int value,int position)
{
    Node* newnode = new Node();
    newnode->data=value;
    if(position<=0)
    {
        cout<<"position is invalid";
        return;
    }
    if (position == 1) //case of insertion at beginning
    {
        insertAtBeg(head,value);
        return;
    }
    Node* current = head; //traverse just before the target position
    for(int i=1;i<position-1 && current !=NULL;i++)
    {
        current=current->next;
    }
    newnode->next=current->next; //new node will now point to current node's next node
    if(current->next!=NULL) //if there is a next node after its previous should point to new node
    {
        current->next->prev=newnode;
    }
    newnode->prev=current; //current node will point to new node
    current->next=newnode; //newnode previous will point to current node

}
void Traversal(Node*& head)
{
    Node* current=head;
    while(current != NULL)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    Node* head=NULL;
    insertAtEnd(head,20);
    insertAtEnd(head,40);
    insertAtBeg(head,10);
    insertAtPosition(head,30,3);
    Traversal(head);
    return 0;
}
