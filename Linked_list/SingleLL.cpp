#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    //pointer of type node
    Node* next; 
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void InsertAtHead(Node* &head,int data)
{
    //allocate memory to new node and via callling constructor create a new node
    Node* temp=new Node(data);
    //new node next points to first node 
    //head points to first node 
    temp->next=head;
    //now head points to new node 
    head=temp;
}

void InsertAtTail(Node* &tail,int data)
{
    //allocate memory to new node and via callling constructor create a new node
    Node* temp=new Node(data);
    //last node should point to new node
    tail->next=temp;
    //now tail should point to new node inserted at last
    tail=tail->next;
}

void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1=new Node(6);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    cout<<"head->data "<<head->data<<endl;
    cout<<"tail->data "<<tail->data<<endl;
    InsertAtHead(head,12);
    cout<<"head->data  "<<head->data<<endl;
    cout<<"tail->data "<<tail->data<<endl;
    InsertAtTail(tail,13);
    cout<<"head->data "<<head->data<<endl;
    cout<<"tail->data "<<tail->data<<endl;
    //print(head);
}   
