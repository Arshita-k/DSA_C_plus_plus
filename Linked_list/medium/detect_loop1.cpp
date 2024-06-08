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
/* 
   O(N), where N is the number of nodes in the linked list. This is because in the worst-case scenario, the fast pointer, which moves quicker,
   will either reach the end of the list (in case of no loop) or meet the slow pointer (in case of a loop) in a linear time relative to the length of the list
   
*/
bool find_loop(Node*& head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
    }
    return false;  
}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next=node2;
    Node* node3 = new Node(3);
    node2->next=node3;
    Node* node4 = new Node(4);
    node3->next=node4;
    node4->next=node2;
    find_loop(node1);
    (find_loop(node1))?cout<<"Loop detected by second method" : cout<<"Loop not detected by second method";
    return 0;
}
/*
The relative speed between them causes the gap to decrease by one node in each iteration (fast gains two nodes while slow gains one node). 
This continuous reduction ensures that the difference between their positions decreases steadily. Mathematically, if the fast pointer 
gains ground twice as fast as the slow pointer, the difference in their positions reduces by one node after each step.
Consequently, this reduction in the distance between them continues until the difference becomes zero.
*/
