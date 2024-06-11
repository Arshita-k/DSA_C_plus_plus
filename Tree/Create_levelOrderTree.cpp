#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() : root(NULL) {}

    void create(Node* root0, vector<int> &vec) 
    {
        int n = vec.size();
        int k = 1;
        queue<Node*>q;
        q.push(root0);
        while(!q.empty() && k<n)
        {
            Node* temp = q.front();
            q.pop();
            temp->left = new Node(vec[k++]);
            q.push(temp->left);
            temp->right = new Node(vec[k++]);
            q.push(temp->right);
        }
    }
};
int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
    BinaryTree B1;
    Node* root=new Node(1);
    B1.create(root,arr);
    B1.printInOrder(root);
}
 /*
class Solution{
public:
    void helper(node* currNode, int indx, vector<int> &vec) {
        if(!currNode) return;
        int n = vec.size();
        int lchild = 2*indx+1;
        int rchild = 2*indx+2;
        
        if(lchild < n) {
            node* lnode = newNode(vec[lchild]);
            currNode->left = lnode;
        }
        if(rchild < n) {
            node* rnode = newNode(vec[rchild]);
            currNode->right = rnode;
        }
        
        helper(currNode->left,2*indx+1,vec);
        helper(currNode->right,2*indx+2,vec);
    }

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        helper(root0, 0, vec);
    }

};

*/
