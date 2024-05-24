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
void deleteAtBeg(Node*& head)
{
    if(head==NULL)
        return;
    Node* temp=head;
    head->next->prev=NULL;
    head=head->next;
    delete temp;
}
void deleteAtEnd(Node*& head) {

    // Find the last node
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    // Update the previous node's next pointer
    Node* prev = nullptr;
    while (prev->next != curr) {
        prev = prev->next;
    }
    prev->next = nullptr;

    // Delete the last node
    delete curr;
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
    insertAtBeg(head,10);
    insertAtBeg(head,20);
    insertAtBeg(head,30);
    insertAtBeg(head,40);
    insertAtBeg(head,50);
    insertAtBeg(head,60);
    //Traversal(head);
    //deleteAtBeg(head);
    deleteAtEnd(head);
    Traversal(head);
    return 0;
}
