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
Node* buildTree(Node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    //base case
    if(data ==-1){return NULL;}
    // recursion
    cout<<"enter data left on data"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data right on data"<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}

void levelOrderTraversal(Node *root){
queue<Node *>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
    Node *temp=q.front();
    q.pop();
    if(temp==NULL){
        cout<<endl;
        if(!q.empty()){
           q.push(NULL);
        }
    }
    else{
        cout<<temp->data<<endl;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
}
int main(){
    Node *root = NULL;
    root=buildTree(root);

    levelOrderTraversal(root);

}
