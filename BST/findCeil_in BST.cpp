#include <bits/stdc++.h>
using namespace std;

//we need to find ceil that is the smallest element that is greater that or equal to the key
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
void findCeil(Node*& root,int key)
{
    int ceil=-1;
    Node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            ceil=temp->data;
            cout<<"CEIL VALUE IS "<<ceil;
        }
        if(key<temp->data)
        {
            ceil=root->data;
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    cout<<"CEIL VALUE IS "<<ceil;
}
int main()
{
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(13);
    findCeil(root,9);
    return 0;
}

/* OUTPUT
CEIL VALUE IS 8
*/
