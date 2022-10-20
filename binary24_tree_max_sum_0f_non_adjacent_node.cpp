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
  //base case
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

pair<int,int>solve(Node *root){
    //base case 
    if(root==NULL){
         pair<int,int>p=make_pair(0,0);
         return p;
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    pair<int,int>res;
    res.first=root->data+left.second+right.second;
    res.second=max(left.first,left.second)+max(right.first,right.second);
    return res;
}

int getmaxsum(Node*root) {
    pair<int, int>ans=solve(root);
    return max(ans.first,ans.second);
    
}

int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    int satya=getmaxsum(root);
    cout<<"max sum is: "<<satya;
}