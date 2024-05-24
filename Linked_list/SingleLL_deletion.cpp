#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
//  pointer_type Node pointer_name 
    Node* next; //pointer to next node 
};
//pass a pointer by reference
void InsertatBeg(Node*& head,Node*& tail,int value)
{
    Node* ptr=new Node();
    ptr->data=value;
    ptr->next=head;
    head=ptr;
    if (tail == NULL)
    {
        tail=ptr;
    }
}
void InsertatEnd(Node*& head,Node*& tail,int value)
{
    Node* ptr=new Node();
    ptr->data=value;
    ptr->next=NULL;
    if (head == NULL){
        head=ptr;
        tail=ptr;
    }
    else {
        tail->next=ptr;
        tail=ptr;
    }
}
void DeletefromBeg(Node*& head,Node*& tail)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return;
    }
    Node* temp=head;//save current head
    head=head->next;//head will point to next node
    if(head==NULL)//if only one node existed and now list is empty
    {
        tail=NULL;//update tail also it will still point to deleted node 
    }
    delete temp;//delete the node
}
void DeletefromEnd(Node*& head,Node*& tail)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty";
        return;
    }
    if(head->next==NULL)//if only one node exists and now list is empty
    {
        delete head;
        head=NULL;
        tail=NULL;
        return;
    }
    Node* current=head;//to have access to second last node
    while(current->next!=tail)//traverse till second last node
    {
        current=current->next;
    }
    delete tail;
    tail=current; //make the second last node the last node
    tail->next=NULL;
}
void DeleteAtPosition(Node*& head,Node*& tail,int position)
{
    if(position<=0||head==NULL){
        cout<<"Invalid position or list is empty";
        return;
    }

    if (position == 1){
        DeletefromBeg(head,tail);
        return;
    } 

    Node* current = head; //for traversal
    for(int i=1;i<position-1 && current != NULL;i++){
        current =current->next;
    }

    if(current==NULL||current->next==NULL){
        cout<<"Position out of range";//if the position just before the target node 
        return;              //or the target node doesn't exist
        
    }

    Node* temp=current->next; //save the node to be delete 
    current->next=temp->next; //make the current node point to target's next node
    if(temp->next==NULL)
    {
        tail=current;
    }
    delete temp; //delete the target node
}
void print_ll(Node* head) //pass pointer head
{
    //we do not want to move head so we will make a temporary pointer
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next; //move to next node
    }
    cout<<"NULL";

}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    InsertatBeg(head,tail,20);
    InsertatBeg(head,tail,10);
    InsertatEnd(head,tail,30);
    InsertatEnd(head,tail,40);
    InsertatEnd(head,tail,50);
    InsertatEnd(head,tail,60);
    //print_ll(head);
    DeletefromBeg(head,tail);
    DeletefromEnd(head,tail);
    DeleteAtPosition(head,tail,3);
    print_ll(head);
}

/* OUTPUT 

20 -> 30 -> 50 -> NULL

*/
