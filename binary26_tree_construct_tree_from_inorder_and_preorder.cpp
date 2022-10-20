//TIME COMPLEXCITY=O(1)
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


Node *solve(int in[], int pre[], int &index, int inorderstart, int inorderend, int n,map<int,int>&nodeToIndex)
{
    // base case
    if (index >= n)
    {
        return NULL;
    }
    if (inorderstart > inorderend)
    {
        return NULL;
    }
    //create root node for element
    int element = pre[index++];
    Node *root = new Node(element);
    //find index in inorder
    int position = nodeToIndex[element];

    // recursion call
    root->left = solve(in, pre, index, inorderstart, position - 1, n,nodeToIndex);
    root->right = solve(in, pre, index,position + 1, inorderend, n,nodeToIndex);
    return root;
}


Node *buildTree(int in[], int pre[], int n)
{
    int preorderindex = 0;
    map<int, int>nodeToIndex;
    creatingMapping(in, nodeToIndex,n);
    Node *ans = solve(in, pre, preorderindex, 0, n - 1, n,nodeToIndex);
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
    int pre[] = {1,6,7,8};
    int len = sizeof(in)/sizeof(int);
 
    Node *root = buildTree(in,pre,len);
 
    printpostorder(root);
    return 0;
}
 