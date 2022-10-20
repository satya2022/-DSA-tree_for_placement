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
Node *buildTree(Node *root)
{

    cout << "enter data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    // base case
    if (data == -1)
    {
        return NULL;
    }
    // recursion
    cout << "enter data on left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data on right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// inorder traversal  (LNR)
void inOrder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// preorder NLR
void preOrder(Node *root)
{

    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//postOrder traverse in tree is(LRN)
void postOrder(Node *root){
    //base case
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
    // inorder traversal
    cout << "inOrderTravarse is" << endl;
    inOrder(root);
    cout<< endl;
    cout << "preorder traverse is" << endl;
    preOrder(root);
    cout<< endl;
    cout << "postorder traverse is" << endl;
    postOrder(root);
}