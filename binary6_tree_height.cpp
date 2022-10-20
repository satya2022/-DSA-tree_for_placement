#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    //construct
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};
Node* buildtree(Node* root){
    cout<<"enter the data"<<endl;
    int data ;
    cin>>data;
     root = new Node(data);
    //base case
    if(data==-1){
        return NULL;
    }
    cout<<"enter data on left of data"<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"enter data on right of data"<<data<<endl;
    root->right = buildtree(root->right);
return root;
}
int height(Node* root) {
    if(root==NULL){ return 0;}
    int left=height(root->left);
    int right=height(root->right);
    int ans =max(left,right)+1;
    return ans;
}
int main(){
    Node *root = NULL;
    root = buildtree(root);
    cout<<"height is"<<height(root)<<endl;
}