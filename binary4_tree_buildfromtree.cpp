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
        this->left =NULL;
        this->right =NULL;
    }
};


void buildfromTree(Node* root) {
    //level order ka metlab queue
    queue<Node*>q;
    int data;
    cout<<"enter data for root"<<endl;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()) {
        Node* temp=q.front();
        q.pop();
        cout<<"enter left node for"<<temp->data<<endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"enter right node for"<<temp->data<<endl;
        int rightnode;
        cin >> rightnode;
        if(rightnode!=-1){
            temp->right=new Node(rightnode);
            q.push(temp->right);
        }
    }
}

int main(){
Node* root=NULL;
// root=buildTree(root);
buildfromTree(root);
    return 0;
}