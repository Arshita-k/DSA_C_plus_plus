#include <bits/stdc++.h>
#define MAX 5
using namespace std;
//Queue follows the principle of "First in,First out where the first element added to the queue is the first one to be removed"
int Queue[MAX],front=0,rear=-1;
void Enqueue(int value)
{
    if(rear==MAX-1)
    {
        cout<<"Queue is Full"<<endl;
    }
    else
    {
        Queue[++rear]=value;
        cout<<"Inserted : "<<value<<endl;
    }
}
void Dequeue()
{
    if(rear<front)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
       int item=Queue[front++];
       cout<<"Extracted element is : "<<item<<endl;
    }
}
void display()
{
    if(rear<front)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        cout<<"Elements in queue are : "<<endl;
        for(int i=front;i<=rear;i++)
        {
            cout<<Queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    Dequeue();
    Enqueue(3);
    Enqueue(1);
    Dequeue();
    Enqueue(2);
    Enqueue(3);
    display();
    Dequeue();
    Dequeue();
    display();
    return 0;
}

/* OUTPUT
Queue is Empty
Inserted : 3
Inserted : 1
Extracted element is : 3
Inserted : 2
Inserted : 3
Elements in queue are :
1 2 3
Extracted element is : 1
Extracted element is : 2
Elements in queue are :
3

A queue is an object (an abstract data structure follows (FIFO) - ADT) that allows the following operations:
Enqueue: Add an element to the end of the queue
Dequeue: Remove an element from the front of the queue
IsEmpty: Check if the queue is empty
IsFull: Check if the queue is full
Peek: Get the value of the front of the queue without removing it
*/
