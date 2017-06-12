#include <iostream>
using namespace std;

// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
    // Base Case
    if (root == NULL || k < 0)  return;

    // If we reach a k distant node, print it
    if (k==0)
    {
        cout << root->data << endl;
        return;
    }

    // Recur for left and right subtrees
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int printkdistanceNode(node* root, node* target , int k)
{
    if(root==NULL)
      return -1;

    if(root->data==target->data){
      printkdistanceNodeDown(root,k);
      return 0;
    }

    int dl=printkdistanceNode(root->left,target,k);
    if(dl!=-1){
    if(dl==0)
      cout<<root->data<<" ";
    else
      printkdistanceNodeDown(root->right,k-dl-2);
      return 1+dl;
  }
  int dr=printkdistanceNode(root->right,target,k);
    if(dr!=-1){

      if(dr==0)
        cout<<root->data<<" ";
      else
        printkdistanceNode(root->left,target,k-dr-2);

      return 1+dr;
      }
    return -1;



}

// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printkdistanceNode(root, target, 2);
    return 0;
}
