#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};
//ITERATIVE APPROACH  // time complexity O(N) and space complexity O(1)
Node* reverse(Node*& head)
{
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        Node* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
//RECURSIVE APPROACH   // time complexity O(N) and space complexity O(1)
Node* reverse2(Node*& head)
{
    if(head==NULL || head->next == NULL)
    {
        return head;
    }
    Node* newhead = reverse(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
void printLinkedList(Node*& head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    head->next=node2;
    Node* node3 = new Node(3);
    node2->next=node3;
    printLinkedList(head);
    head=reverse(head);
    printLinkedList(head);
    return 0;
    // Node* node4 = new Node(4);
    // node3->next=node4;
    // Node* node5 = new Node(5);
    // node4->next=node5;
}
/*
OUTPUT

1 -> 2 -> 3 
3 -> 2 -> 1 

*/
