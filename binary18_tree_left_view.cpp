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

void solve(Node *root,vector<int>&ans,int level) {
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);

}
vector<int> leftView(Node *root){
vector<int> ans;
if(root==NULL){return ans;}
solve(root,ans,0);
return ans;
}

int main()
{
    Node *root = NULL;
    root = buildtree(root);

    vector<int> res = leftView(root);
    cout << "leftView traversal of binary tree is:" << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}