#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int value)
    {
        data=value;
        next=NULL;
    }
};
class Queue {
    public:
    node* front;
    node* rear;

    Queue() { front = rear = NULL;}
    void Enqueue(int value)
    {
       node* temp=new node(value);
       if(rear==NULL)
       {
            front=rear=temp;
            return;
       }
       rear->next=temp;
       rear=temp;
    }
    void Dequeue()
    {
        //if front points to null queue is empty
        if(front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        node* temp=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete temp;
    }
    void display()
    {
        if(front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        node* temp=front;
        cout<<"Elements in queue are : ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    Queue Q;
    Q.Enqueue(3);
    Q.display();
    Q.Enqueue(1);
    Q.Dequeue();
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.display();
    return 0;
}
/*
OUTPUT
Elements in queue are: 3 
Queue is Empty
Elements in queue are: 2 3 

*/
