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

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void solve(Node *root, int sum, int &maxsum, int len, int &maxlen)
{
    // base case
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxsum, len, maxlen);
    solve(root->right, sum, maxsum, len, maxlen);
}

int sumofLongestLefepath(Node *root)
{
    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxsum = INT_MIN;
    solve(root, sum, maxsum, len, maxlen);
    return maxsum;
}

int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);

    cout << sumofLongestLefepath(root) << endl;

    return 0;
}