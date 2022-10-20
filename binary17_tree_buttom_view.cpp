#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // construct
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildtree(Node *root)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    // base case
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data on left of data" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data on right of data" << data << endl;
    root->right = buildtree(root->right);
    return root;
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL){
        return ans;
    }
    map<int, int> topNode;
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;
       
            topNode[hd] = frontNode->data;
        

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildtree(root);

    vector<int> res = topView(root);
    cout << "buttom traversal of binary tree is:" << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}