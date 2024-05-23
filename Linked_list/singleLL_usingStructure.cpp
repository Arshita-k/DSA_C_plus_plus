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
   // ptr refers new node created
    Node* ptr=new Node();
    ptr->data=value;
    ptr->next=head; //newnode point to the previous first node hence its the first node now
    head=ptr; //head points to new node
    if (tail == NULL) //its the first and only node present so both head and tail will point to new node
    {
        tail=ptr;
    }
}
void InsertatEnd(Node*& head,Node*& tail,int value)
{
    Node* ptr=new Node();
    ptr->data=value;
    ptr->next=NULL;
    if (head == NULL){   //empty linked list
        head=ptr;
        tail=ptr;
    }
    else {
        tail->next=ptr; //make the current last node point to new node
        tail=ptr;  //tail now point to new node
    }
}
void InsertatPosition(Node*& head,Node*& tail,int value,int position)
{
    if (position <= 0)
    {
        cout<<"Invalid position";
        return;
    }
    if (position == 1)
    {
        InsertatBeg(head,tail,value);
        return;
    }
    Node* ptr=new Node();
    ptr->data=value;
    Node* current = head;
    for(int i=1;i<position-1 && current != NULL;i++){ //traverse till the node just before the position and also check that u don't exceed end
            current = current->next;
    }  
    if(current == NULL)  
    {
        cout<<"Position out of range";
        delete ptr;
        return;
    }
    ptr->next=current->next;
    current->next=ptr;
    if(ptr->next==NULL){ //last node
        tail=ptr;
    }
    
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
    InsertatEnd(head,tail,40);
    InsertatEnd(head,tail,50);
    InsertatPosition(head,tail,30,3);
    print_ll(head);
}
