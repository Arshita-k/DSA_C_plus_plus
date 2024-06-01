#include <bits/stdc++.h>
using namespace std;
#define MAX 5
int front =-1,rear = -1;
int Deque[MAX];
void EnQueuefront(int value)
{
    if((front==0 && rear==MAX-1)|| (front==rear+1)) 
    {
        cout<<"Deque is Full"<<endl;
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0; 
        Deque[front]=value;
        cout<<value<<" Inserted from front "<<endl;
    }
    else if(front==0)
    {
        front=MAX-1;
        Deque[front]=value;
        cout<<value<<" Inserted from front"<<endl;
    }
    else
    {
        Deque[--front]=value;
        cout<<value<<" Inserted from front"<<endl;
    }
}
void EnqueueRear(int value)
{
    if((front==0 && rear==MAX-1)|| (front==rear+1)) 
    {
        cout<<"Queue is Full"<<endl;
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0; 
        Deque[rear]=value;
        cout<<value<<" Inserted from rear "<<endl;
    }
    else if(rear==MAX-1)
    {
        rear=0;
        Deque[rear]=value;
        cout<<value<<" Inserted from rear"<<endl;
    }
    else
    {
        Deque[++rear]=value;
        cout<<value<<" Inserted from rear"<<endl;
    }
}
void getfront()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is Empty"<<endl;
        return;
    }
    cout<<Deque[front]<<" is the value at front"<<endl;
}
void getRear()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is Empty"<<endl;
        return;
    }
    cout<<Deque[rear]<<" is the value at rear"<<endl;
}
void DeQueuefront()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is Empty"<<endl;
        return;
    }
    else if(front==rear)//last element is target
    {
        cout<<"Extracted element is"<<Deque[front]<<endl;
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        cout<<"Extracted element is"<<Deque[front]<<endl;
        front=0;
    }
    else
    {
        cout<<"Extracted element is"<<Deque[front]<<endl;
        front++;
    }
}
void DeQueueRear()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is Empty"<<endl;
        return;
    }
    else if(front==rear)//last element is target
    {
        cout<<"Extracted element is"<<Deque[front]<<endl;
        front=rear=-1;
    }
    else if(rear==0)
    {
        cout<<"Extracted element is"<<Deque[rear]<<endl;
        rear=MAX-1;
    }
    else
    {
        cout<<"Extracted element is"<<Deque[rear]<<endl;
        rear--;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        cout<<"Deque is Empty"<<endl;
        return;
    }
    else
    {
        while(i!=rear)
        {
            cout<<Deque[i]<<" ";
            i=(i+1)%MAX;
        }
        cout<<Deque[rear]<<endl;
    }
}
int main()
{
    // 1 2 3 4 5
    DeQueuefront();
    EnQueuefront(-1);
    EnqueueRear(2);
    EnqueueRear(3);
    EnqueueRear(4);
    EnqueueRear(5);
    EnqueueRear(6);
    DeQueuefront();
    EnQueuefront(1);
    display();
    getfront();
    getRear();
    return 0;
}
/* OUTPUT

DQueue is Empty
-1 Inserted from front 
2 Inserted from rear
3 Inserted from rear
4 Inserted from rear
5 Inserted from rear
Queue is Full
Extracted element is-1
1 Inserted from front
1 2 3 4 5
1 is the value at front
5 is the value at rear

*/
