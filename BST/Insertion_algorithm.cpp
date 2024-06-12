#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
//iterative
void Insertion(Node*& root,int key)
{
    //Iteratively search if the new key is already present in the tre or not
    bool found=false;
    Node* temp=root;
    Node* current;
    while((temp!=NULL) && !found)
    {
        current = temp; // we are saving current so that we can insert the new node at the correct position
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
    {
        Node* temp=new Node(key);
        if(root!=NULL)
        {
            if(key<(current->data))
            {
                current->left=temp;
            }
            else
            {
                current->right=temp;  
            }
        }
        else
        {
            root=temp;
        }
    }
    else
        cout<<"Number is already there in the BST"<<endl;
}
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
    root->right->right->left = new Node(13);
    cout<<"Enter number to be searched : ";
    cin>>num;
    //InOrder(root);
    Insertion(root,num);
    InOrder(root);
    return 0;
}
/* isme approach ye the ki phele hum pure tree mei search karenge but in bst we stop 
at the node jhn vo key honi chaiye for example in case of 9 we have root node 8 so hum right subtree mei
dhudenge because 8 < 9 then we have  12 as root node now hum uske left subtree mei jayenge kyunki 
12 > 9 now root node is 10 so we will check left subtree again but yhn toh koyi node nhi so we will return but current = 10  
we saved and insertion ke time according vhn node insert kar denge 


OUTPUT
Enter number to be searched : 8
Number is already there in the BST
4 5 6 7 8 10 12 13 14  //inorder traversal
Enter number to be searched : 9
4 5 6 7 8 9 10 12 13 14 
 */

