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
//brute force time complexity O(N * 2 * logN)
//The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)).
//the loop iterates through N nodes O(N)
void find_loop(Node*& head)
{
    Node* temp=head;
    map<int,int>mpp;
    while(temp!=NULL)
    {
        if(mpp[temp->data]!=1)
        {
            mpp[temp->data]++;
            temp=temp->next;
        }
        else
        {
            cout<<"There is a loop"<<endl;
            return;
        }
    }
    cout<<"There is no loop"<<endl;
}
bool detectLoop(Node*& head)
{
    Node* temp=head;
    //here we are using node as the key
    unordered_map<Node*,int>map;
    while(temp!=NULL)
    {
        //map.find() Returns an iterator to the element with key-value ‘temp’ in the map if found, else returns the iterator to end.
        //map.end() returns an iterator to the theoretical element that follows the last element in the map
        if(map.find(temp)!=map.end())
        {
            return true; //same node found twice loop detected
        }
        map[temp]=1; //if node not present previously then makes it value 1
        temp=temp->next; //move to next node
    }
    return false; //loop not present
}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5; // 1->2->3->4->5->NULL
    //node5->next=node3; // 1->2->3->4->5->3 if we execute this loop will be there
    find_loop(node1);
    (detectLoop(node1))?cout<<"Loop detected by second method" : cout<<"Loop not detected by second method";
    return 0;
}

/* 
OUTPUT

There is no loop
Loop not detected by second method

*/
