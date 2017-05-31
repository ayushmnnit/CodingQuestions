// C++ Program to print Bottom View of Binary Tree
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

// Tree node class
struct Node
{
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        hd = INT_MAX;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root)
{
    queue<Node *> q;
    map<int,int> m;
    Node *top;
    if (root==NULL) {
      return;
    }
    root->hd=0;
    m[0]=root->data;
    q.push(root);

    while(!q.empty()){

      top=q.front();
      q.pop();

      if(top->left)
      {
        q.push(top->left);
        top->left->hd=(top->hd)-1;
        m[top->left->hd]=top->left->data;
      }

      if(top->right)
      {
        q.push(top->right);
        top->right->hd=(top->hd)+1;
        m[top->right->hd]=top->right->data;
      }

    }
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";

}

// Driver Code
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;
}
