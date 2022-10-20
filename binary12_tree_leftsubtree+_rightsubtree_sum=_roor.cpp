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

pair<bool,int>issumtreefast(Node *root){
    //base case
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL&&root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int>leftans=issumtreefast(root->left);
    pair<bool,int>rightans=issumtreefast(root->right);

    bool isleftsumtree=leftans.first;
    bool isrightsumtree=rightans.first;

    int leftsum=leftans.second;
    int rightsum=rightans.second;

    bool condition=root->data==leftsum+rightsum;
    pair<bool,int>ans;

    if(isleftsumtree&&isrightsumtree&&condition){
        ans.first=true;
        ans.second=root->data+leftsum+rightsum;

    }
    else{
        ans.first=false;
    }
    return ans;
}

bool issumtree(Node *root){
    return issumtreefast(root).first;
}


int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    cout << "tree issumtree"<<issumtree(root);
   
}