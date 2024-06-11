#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
//as when i was returning array in the same function it was just printing root not all nodes were stored 
void PreOrder_helper(Node*& root,vector<int>&arr)
{
    if(root==NULL)
    {
        return;
    }
    arr.push_back(root->data);
    PreOrder_helper(root->left,arr);
    PreOrder_helper(root->right,arr);
}
vector<int> PreOrder(Node*& root)
{
    vector<int>array;
    PreOrder_helper(root,array);
    return array;
}
/*
void PreOrder(Node*& root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
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
    vector<int>result=PreOrder(root);
    cout<<" Preorder Traversal: ";
    for(auto value : result)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}


/* 
OUTPUT 

 Preorder Traversal: 4 2 3 9 1 5 7 6 8 

*/
