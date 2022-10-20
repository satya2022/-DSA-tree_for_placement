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
    // base case
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

vector<int> zigzag(Node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    queue<Node *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        // level ko proces karana hai
        int size = q.size();
        vector<int> ans(size);
        // level proces
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            // normal insert and reverse insert
            int index = lefttoright ? i : size-i - 1;
            ans[index] = frontNode->data;
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        // direction cnge karni hogi
        lefttoright =! lefttoright;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    /*
std::vector<char> path;
// ...
for (char i: path)
 std::cout << i << ' ';
    */

  vector <int> res = zigzag(root);
      cout<<"ZigZag traversal of binary tree is:"<<endl;
    for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
    cout<<endl;
}