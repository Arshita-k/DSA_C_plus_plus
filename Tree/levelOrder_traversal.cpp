#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int value) : data(value), left(NULL), right(NULL) {}
    Node(int value,Node* left,Node* right) : data(value), left(left), right(right) {}
};
//Method1 
vector<vector<int>> levelorder(Node* root)
{
    vector<vector<int>>answer; //return type
    if(root==NULL)
    {
        return answer;
    }
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        int size=Q.size();
        vector<int>temp; //to store current level nodes
        for(int i=0;i<size;i++)
        {
            Node* newnode=Q.front();
            Q.pop();
            temp.push_back(newnode->data);
            cout<<newnode->data<<" ";
            if(newnode->left!=NULL)
            {
                Q.push(newnode->left);
            }
            if(newnode->right!=NULL)
            {
                Q.push(newnode->right);
            }
        }
        cout<<endl;
        answer.push_back(temp);
    }
    return answer;
}

// Function to print
// the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the
    // vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
//Method2 void return type
void Levelorder(Node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
    }
    queue<Node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        int size=Q.size();
        for(int i=0;i<size;i++) //to traverse the current level 
        {
            Node* newnode=Q.front();
            Q.pop();
            cout<<newnode->data<<" ";
            if(newnode->left!=NULL)
            {
                Q.push(newnode->left);
            }
            if(newnode->right!=NULL)
            {
                Q.push(newnode->right);
            }
        }
        cout<<endl;
    }
}

int main()
{
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->right->left=new Node(7);
    vector<vector<int>>result=levelorder(root);
    Levelorder(root);
    for (const vector<int>& level : result) {
        printVector(level);
    }
    return 0;
}
