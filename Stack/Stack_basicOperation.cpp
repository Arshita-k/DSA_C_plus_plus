#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Stack {
    int top;
    public:
    int Array[MAX];
    Stack() { top = -1; }
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
};
void Stack::push(int value){
    if(top >=MAX-1){
        cout<<"Stack Overflows";
        return;
    }
    else {
        Array[++top]=value;
        cout<<value<<" is pushed into the stack"<<endl;
    }

}
int Stack::pop()
{
    int value;
    if(top<=-1){
        cout<<"Stack Underflows"<<endl;
        return 0;
    }
    else{
        value=Array[top--];
        return value;
    }
}
int Stack::peek()
{
    int value;
    if(top==-1){
        cout<<"Stack Underflows"<<endl;
        return 0;
    }
    else{
        value=Array[top];
        return value;
    }
}
bool Stack::isEmpty()
{
    if(top<=-1){
        return true;
    }
    else{
        return false;
    }
}
bool Stack::isFull()
{
    if(top>=MAX-1){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    Stack S1;
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);
    cout<<S1.pop()<<" Popped from stack"<<endl;
    cout<<S1.peek()<<" is top element of stack"<<endl;
    return 0;
}
