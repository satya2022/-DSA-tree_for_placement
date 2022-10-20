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

Node* solve(Node* root,int &k,int node){
    //base case 
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){return root;}
    Node* leftans=solve(root->left,k,node);
    Node* rightans=solve(root->right,k,node);
    if(leftans!=NULL&&rightans==NULL){
        k--;
        if(k<=0){
            //ans lock kar do
            k=INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL&&rightans!=NULL){
        k--;
        if(k<=0){
            //ans lock kar do
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int kthancestor(Node *root,int k,int node){
    Node* ans=solve(root,k,node);
    if(ans==NULL||ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    int k=2,node=4;
    int satya=kthancestor(root,k,node);
    cout<<"k th ancestor is"<<satya<<endl;

    return 0;
}