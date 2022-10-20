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

Node* lca(Node* root,int n1,int n2){
    //base case
    if(root==NULL){return NULL;}
    if(root->data==n1||root->data==n2){return root;}
    Node* leftans=lca(root->left,n1,n2);
    Node* rightans=lca(root->right,n1,n2);
    if(leftans!=NULL && rightans!=NULL){
        return root;
    }
     else if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL && rightans!=NULL){
        return rightans;
    }
   
    
    else{return NULL;}
}


int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
      int n1,n2;
    cout<<"enter value of n1 "<<endl;
    cin>>n1;
    cout<<"enter value of n2 "<<endl;
    cin>>n2;
    Node *satya=lca(root,n1,n2);
      if (lca != NULL)
        cout << "LCA(8, 27) = " << satya->data;
    else
        cout << "Keys are not present ";
 
    return 0;
}