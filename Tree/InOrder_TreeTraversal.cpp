#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
//as when returning array in the same function it was just printing root not all nodes were stored 
void InOrder_helper(Node*& root,vector<int>&arr)
{
    if(root==NULL)
    {
        return;
    }
    InOrder_helper(root->left,arr);
    arr.push_back(root->data);
    InOrder_helper(root->right,arr);
}
vector<int> InOrder(Node*& root)
{
    vector<int>array;
    InOrder_helper(root,array);
    return array;
}
/* if we want to directly print post order
void InOrder(Node*& root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
*/
int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->right->left=new Node(7);
    root->right->right=new Node(6);
    root->left->left->right=new Node(9);
    root->right->right->left=new Node(8);
    root->left->left->right->left=new Node(1);
    vector<int>result=InOrder(root);
    //InOrder(root);
    cout<<" InOrder Traversal: ";
    for(auto value : result)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}

/* 
OUTPUT


 InOrder Traversal: 3 1 9 2 4 7 5 8 6 

*/
