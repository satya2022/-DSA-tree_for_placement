#include<bits\stdc++.h>
using namespace std;
class Node{
public:
int data; 
Node* left;
Node* right;
//constructor
Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};

Node* biuldTree(Node* &root){
cout<<"enter the data"<<endl;
int data;
cin>>data;
root =new Node(data);
if(data==-1){
    return NULL;
}
cout<<"enter data for insrting in left of"<<data<<endl;
//recursion1
root->left =biuldTree(root->left);
cout<<"enter data for insrting in right of"<<data<<endl;
root->right =biuldTree(root->right);
return root;

}
int main(){   

Node* root = NULL;
//creatig a tree 
root=biuldTree(root);

    return 0;
}