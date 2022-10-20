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

pair<bool,int> isblancedfast(Node* root) {
    //base case
    if(root==NULL){ 
        pair<bool,int>p=make_pair(true,0);
        return p;
        }
    pair<int,int>left=isblancedfast(root->left);
    pair<int,int>right=isblancedfast(root->right);
    bool leftans=left.first;
    bool rightans=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;

    if(leftans&&rightans&&diff)
    {
        ans.first=true;
    }
    else{
        ans.second=false; 
        }
        return ans;
}

bool isblanced(Node* root){
    return isblancedfast(root).first;
}
int main(){
    Node * root=NULL;
    root=buildTree(root);
   cout<<"balancese" <<isblanced(root);
}