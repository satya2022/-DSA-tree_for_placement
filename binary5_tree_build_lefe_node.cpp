#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* left;
    Node* right;
    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    //base case
    if(data==-1){
        return NULL;
    }
    cout<<"enter data in left of"<<data<<endl;
   root->left=buildTree(root->left);
   cout<<"enter data in right of"<<data<<endl;
   root->right=buildTree(root->right);
   return root;
}
//traverse tree
void inorder(Node *root,int &count){
    //base case(LNR)
    if(root==NULL){
        return;
    }
    inorder(root->left,count);
    if(root->left==NULL&&root->right==NULL){
        count ++;
    }
    cout<<root->data<<" ";
    inorder(root->right,count);
    
}
int lefenodecount(Node *root){
    int count = 0;
    inorder (root,count);
    return count;
}
int main(){
    Node* root=NULL;
    root=buildTree(root);
    //traverse tree
    int num;
   num= lefenodecount(root);

    cout<<"number of lefe node is"<<" "<<num<<endl;

}