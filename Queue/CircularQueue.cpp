//A Circular Queue is an extended version of a normal queue where the last element of the queue is connected to the first element of the queue forming a circle.
#include <bits/stdc++.h>
using namespace std;
#define MAX 4
int front =-1,rear = -1;
int Queue[MAX];

void Enqueue(int value)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0; //intialise to zero index
        Queue[rear]=value;
        cout<<value<<" Inserted"<<endl;
    }
    else if((rear+1)%MAX==front) //if rear reaches last and front points to first index 0 , max=5 rear reaches (4+1) => 5%5 = 0 = front
    {
        cout<<"Queue is Full"<<endl;
    }
    else
    {
        rear=(rear+1)%MAX; //if we will do rear++ then it will not direct to empty space in the begining
        Queue[rear]=value;
        cout<<value<<" Inserted"<<endl;
    }
}
void Dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else if(front==rear)//last element is target
    {
        cout<<"Extracted element is"<<Queue[front]<<endl;
    }
    else
    {
        cout<<"Extracted element is"<<Queue[front]<<endl;
        front=(front+1)%MAX;
    }
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        while(i!=rear)
        {
            cout<<Queue[i]<<" ";
            i=(i+1)%MAX;
        }
        cout<<Queue[rear]<<endl;
    }
}
int main()
{
    Dequeue();
    Enqueue(-1);
    Enqueue(2);
    Enqueue(5);
    Enqueue(4);
    display();
    Enqueue(3);
    Dequeue();
    Dequeue();
    display();
    return 0;
}
/*
OUTPUT
Queue is Empty
-1 Inserted
2 Inserted
5 Inserted
4 Inserted
-1 2 5 4
Queue is Full
Extracted element is-1
Extracted element is2
5 4
*/
