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
void PostOrder_helper(Node*& root,vector<int>&arr)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder_helper(root->left,arr);
    PostOrder_helper(root->right,arr);
    arr.push_back(root->data);
}
vector<int> PostOrder(Node*& root)
{
    vector<int>array;
    PostOrder_helper(root,array);
    return array;
}
/* if we want to directly print post order
void PostOrder(Node*& root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
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
    vector<int>result=PostOrder(root);
    //PostOrder(root);
    cout<<" Postorder Traversal: ";
    for(auto value : result)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}
/* 
OUTPUT

 Postorder Traversal: 1 9 3 2 7 8 6 5 4 

*/

