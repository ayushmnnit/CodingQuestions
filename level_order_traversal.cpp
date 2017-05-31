/* C++ program to print level order traversal using STL */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};

// Iterative method to find height of Bianry Tree
void printLevelOrder(Node *root)
{
    if(root==NULL)
      return;

    Node *node;

    queue<Node *> q;

    q.push(root);

    while(!q.empty()){

      node=q.front();

      cout<<node->data<<" ";

      q.pop();

      if(node->left)
        q.push(node->left);

      if(node->right)
        q.push(node->right);


    }
}

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
    return 0;
}
