#include<bits\stdc++.h>
using namespace std;
class Node {
    public:
    int data; 
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left =this->right =NULL;
    }
};
Node* buildTree(Node* root){
    cout<<"enter the data"<<endl;
    int data;  
    cin >> data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data on left of data"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data on right of data"<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}
int burnTree(Node *root,map<Node *,Node *> &nodetoparent){
    map<Node *,bool>visited;
    queue<Node *>q;
     q.push(root);
     visited[root] = true;
     int ans = 0;
     while(!q.empty()){
    bool flag = false;
        int size = q.size();
        for(int i=0;i<size;i++){
            //process neighbouring nodes
            Node *front = q.front();
            q.pop();
            if(front->left&&(!visited[front->left])){
              flag=1;
              q.push(front->left);
              visited[front->left]=true;
            }
            if(front->right&&(!visited[front->right])){
              flag=1;
              q.push(front->right);
              visited[front->right]=true;
            }
            if(nodetoparent[front]&&!visited[nodetoparent[front]]){
                flag=1;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]]=1;

            }
        }
        if(flag==1){ ans++;}

     }
     return ans;

}
//create Mapping
//return target Node
Node* createParentMapping(Node* root,int target,map<Node*,Node*>&nodetoparent){
    Node* res=NULL;
    queue<Node*>q;
    q.push(root);
    nodetoparent[root]=NULL;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front->data==target){
            res=front;
        }
        if(front->left){
            nodetoparent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoparent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}
int minTime(Node *root,int target){
    //Stape-1=create nodeto parent mapping
    //Stape-2=find target node
    //Stape-3=burn the tree in minTime
    map<Node *,Node *>nodetoparent;
    Node *targetNode=createParentMapping(root,target,nodetoparent);
    int ans=burnTree(targetNode,nodetoparent);
    return ans;


}
int main(){
    Node* root=NULL;
    root=buildTree(root);
    int target=8;
    int satya=minTime(root,target);
    cout<<"min time to burn tree: "<<satya;

    return 0;
}