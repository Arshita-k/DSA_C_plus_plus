#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
//recursive
bool Search(Node*& root,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data==key)
    {
        return true;
    }
    else if(key < root->data)
    {
        return Search(root->left,key);
    }
    else
    {
        return Search(root->right,key);
    }
}
//iterative
void Search2(Node*& root,int key)
{
    bool found=false;
    Node* temp=root;
    while((temp!=NULL) && !found)
    {
        if(temp->data==key)
        {
            found =true;
        }
        else if(key<temp->data)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(!found)
        cout<<"Number is not there in the BST"<<endl;
    else
        cout<<"Number is there in the BST"<<endl;
}
int main()
{
    int num;
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(14);
    cout<<"Enter number to be searched : ";
    cin>>num;
    if(Search(root,num))
    {
        cout<<"Number is found"<<endl;
    }
    else
    {
        cout<<"Number is not found"<<endl;
    }
    Search2(root,num);
    return 0;
}

/* OUTPUT
Enter number to be searched : 8
Number is found
Number is there in the BST

Enter number to be searched : 1
Number is not found
Number is not there in the BST 
*/
