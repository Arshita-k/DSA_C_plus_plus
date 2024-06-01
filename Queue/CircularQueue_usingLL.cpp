#include <bits/stdc++.h>
using namespace std;
//circular queue using linked list last node should point to first node
//enqueue and deque should take O(1) time
//will maintain head and tail pointers that is front and rear 
struct node
{
    int data;
    node* next;
        node(int value)
        {
            data=value;
            next=NULL;
            //cout<<value<<" inserted"<<endl;
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
            front=rear=temp; //both front and rear will point to the first and only node
            rear->next=front;//last node should point tho first node that is itself
            cout<<rear->data<<" is inserted "  <<endl;
           
       }
       else
       {
            rear->next=temp;//rear will point to new node
            rear=temp;//rear will store address of new node
            rear->next=front;//last node should point tho first node 
            cout<<rear->data<<" is inserted at rear"<<endl;
            cout<<front->data<<" is front value"<<endl;
           
       }
    }
    void Dequeue()
    {
        //if front points to null queue is empty
        node* temp=front;
        if(front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else if(front==rear)
        {
            cout<<front->data<<" is extracted and deleted from queue"<<endl;
            front=rear=NULL; //if only one node is present in queue
            delete temp; //free the memory
        }
        else
        {
            cout<<front->data<<" is extracted and deleted from queue"<<endl;
            front=front->next; //front will point to next node
            rear->next=front; //now rear will point to next front node
            delete temp; //free the memory 
        }
    }
    void peek()
    {
        if(front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<front->data<<" is the front value "<<endl;
    }
    void display()
    {
        if(front==NULL)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        node* temp=front;
        cout<<"Elements in queue are : "<<endl;
        while(temp->next!=front) //last node contains address of first node
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" "; //we can also use do-while loop here 
        cout<<endl;
    }
};
int main()
{
    Queue Q;
    Q.Dequeue();
    Q.Enqueue(3);
    Q.display();
    Q.Enqueue(1);
    Q.Dequeue();
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.display();
    Q.peek();
    return 0;
}
/* 
OUTPUT
Queue is Empty
3 is inserted 
Elements in queue are : 
3 
1 is inserted at rear
3 is front value
3 is extracted and deleted from queue
2 is inserted at rear
1 is front value
3 is inserted at rear
1 is front value
Elements in queue are : 
1 2 3 
1 is the front value 
*/
