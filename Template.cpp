#include <iostream>
#include <queue>
#include <string>

using namespace std;
// Declares a template with a type placeholder T (so T work as a type just link int, double, float, string etc...)
template <typename T> 
struct Node{
    // The data in the node will be of type T.
    T value; 
// The pointers must also point to a Node of the same type T
    Node<T>* left;
    Node<T>* right;
    
    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};
template <typename T> 
void levelOrderTraversal(Node<T>* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    // 1. Create a queue of node pointers
    queue<Node<T>*> q;
    // 2. Add the root node to the queue
    q.push(root);
    // 3. Loop as long as the queue is not empty
    
    while (!q.empty()) {
        // 4. Dequeue the node at the front
        Node<T>* current = q.front();
        q.pop();
        // 5. Print its value
        cout << current->value << " ";
        // 6. Enqueue its left child if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // 7. Enqueue its right child if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}
template <typename T> 
void printMaxAtEachLevel(Node<T>* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node<T>*> q;
    q.push(root);

    while (!q.empty()) {
        // 1. Get the number of nodes at the current level
        int levelSize = q.size();
        
        // 2. Initialize a variable to hold the max value for this level
        T levelMax = q.front()->value; // Initialize with the first node's value

        // 3. Loop through all nodes of the current level
        for (int i = 0; i < levelSize; ++i) {
            Node<T>* currentNode = q.front();
            q.pop();

            // 4. Update the max value if the current node is greater
            levelMax = max(levelMax, currentNode->value);

            // 5. Add children to the queue for the next level
            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }

        // 6. After iterating through the level, print the max value
        cout << levelMax << " ";
    }
    cout << endl;
}
int main() {
    // Instantiating the template with 'int'
    // The compiler generates a 'Node<int>' struct behind the scenes
    Node<int>* root = new Node<int>(10);

    // Accessing the value is straightforward
    cout << "Root value: " << root->value << endl; // Prints 10

    // Creating more nodes and linking them
    root->left = new Node<int>(5);
    root->right = new Node<int>(15);
    root->left->left = new Node<int>(3);
    root->left->right = new Node<int>(7);
    printMaxAtEachLevel(root);
    // Let's create a tree of a DIFFERENT type using the SAME template!
    Node<string>* stringRoot = new Node<string>("CEO");
    stringRoot->left = new Node<string>("Manager");
    stringRoot->right = new Node<string>("Director");

    cout<< "String root value: "<< stringRoot->value << endl; 
    // Prints "CEO"
}
