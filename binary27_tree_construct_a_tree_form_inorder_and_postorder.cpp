#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


void creatingMapping(int in[], map<int, int>&nodeToIndex,int n)
{
    for (int i = 0; i < n; i++)
    {
         nodeToIndex[in[i]] = i;
    }
}


Node *solve(int in[], int post[], int &index, int inorderstart, int inorderend, int n,map<int,int>&nodeToIndex)
{
    // base case
    //move right to left
    if (index <0)
    {
        return NULL;
    }
    if (inorderstart > inorderend)
    {
        return NULL;
    }
    //create root node for element
    int element = post[index--];
    Node *root = new Node(element);
    //find index in inorder
    int position = nodeToIndex[element];

    // recursion call[in case of postorder and inorder we first create subtree]
    root->right = solve(in, post, index,position + 1, inorderend, n,nodeToIndex);
    root->left = solve(in, post, index, inorderstart, position - 1, n,nodeToIndex);
    return root;
}


Node *buildTree(int in[], int post[], int n)
{
    int preorderindex = n-1;
    map<int, int>nodeToIndex;
    //create node to index
    creatingMapping(in, nodeToIndex,n);
    Node *ans = solve(in, post, preorderindex, 0, n - 1, n,nodeToIndex);
    return ans;
}


// Function to print tree in postorder
void printpostorder(Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printpostorder(node->left);
 
     /* now recur on right child */
    printpostorder(node->right);

    /* then print the data of node */
    cout << node->data << " ";
 

}
 
// Driver code
int main()
{
    int in[] = {1,6,8,7};
    int post[] = {1,6,7,8};
    int len = sizeof(in)/sizeof(int);
 
    Node *root = buildTree(in,post,len);
 
    printpostorder(root);
    return 0;
}
 