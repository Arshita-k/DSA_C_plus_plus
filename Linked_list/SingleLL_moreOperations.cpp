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
bool search_iterative(Node*& head,int x){
    
    if(head==NULL)
    {
        return false;
    }
    Node* temp=head;
    //traverse linked list
    while(temp != NULL){
        //check if element is present or not
        if(temp->data==x)
            return true;
        temp=temp->next;
    }
    return false;
}
bool search_recursive(Node*& head,int x){

//if linked list is empty    
    if(head==NULL)
    {
        return false;
    }
    Node* temp=head;
    //base condition if element is found return true
    if(temp->data==x){
        return true;
    }
    return search_recursive(temp->next,x);
}
int length_iterative(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int length_recursive(Node* head){
    
    //Base condition
    if(head==NULL)
        return 0;
    else{
        return 1 + length_recursive(head->next);
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
    InsertatEnd(head,tail,30);
    InsertatEnd(head,tail,40);
    InsertatEnd(head,tail,50);
    InsertatEnd(head,tail,60);
    search_recursive(head,20)?cout<<"Yes" : cout << "No";
    cout<<endl;
    search_iterative(head,70)?cout<<"Yes" : cout << "No";
    cout<<endl;
    cout<<"Length of linked list is: "<<length_iterative(head)<<endl;
    cout<<"Length of linked list is: "<<length_recursive(head)<<endl;
    return 0;
}
