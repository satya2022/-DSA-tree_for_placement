#include<bits\stdc++.h>
using namespace std;
class Node {
    public:
    int data; 
    Node* left; 
    Node* right;
    //costructor
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
    cout<<"enter data on left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data on right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
int height(Node* root) {
    if(root==NULL){ return 0;}
    int left=height(root->left);
    int right=height(root->right);
    int ans =max(left,right)+1;
    return ans;
}
bool isblanced(Node* root) {
    //base case
    if(root==NULL){ return true;}
    bool left=isblanced(root->left);
    bool right=isblanced(root->right);
    bool diff=height(root->left)-height(root->right)<=1;
    if(left&&right&&diff){return true;}
    else{return false;}
}
int main(){
    Node * root=NULL;
    root=buildTree(root);
   cout<<"balancese" <<isblanced(root);
}