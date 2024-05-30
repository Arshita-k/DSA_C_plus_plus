#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class Queue {
    private:
    int QUEUE[MAX];
    int front;
    int rear;
    public:
    Queue() { front = 0, rear = -1 ;}
    void Enqueue(int value)
    {
        if(rear==MAX-1)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            QUEUE[++rear]=value;
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
            int item=QUEUE[front++];
            cout<<"Extracted element is : "<<item<<endl;
        }
    }
    void ShowFront()
    {
        if(rear<front)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            cout<<"Element at front is : "<<QUEUE[front]<<endl;
        }
        
    }
    void ShowRear()
    {
        if(rear==MAX-1)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            cout<<"Element at rear is : "<<QUEUE[rear]<<endl;
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
                cout<<QUEUE[i]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Queue Q;
    Q.Dequeue();
    Q.Enqueue(3);
    Q.Enqueue(1);
    Q.Dequeue();
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.ShowFront();
    Q.ShowRear();
    Q.Dequeue();
    Q.Dequeue();
    Q.ShowFront();
    return 0;

}

/* OUTPUT
Queue is Empty
Inserted : 3
Inserted : 1
Extracted element is : 3
Inserted : 2
Inserted : 3
Element at front is : 1
Element at rear is : 3
Extracted element is : 1
Extracted element is : 2
Element at front is : 3
*/
