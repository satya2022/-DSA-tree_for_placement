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


   void  solve(Node* root, int k,int &count,vector<int>path){
    //base case 
    if(root==NULL){return;}
    path.push_back(root->data);
    //left
    solve(root->left,k,count,path);
    //right
     solve(root->right,k,count,path);
    // chak for k sum 
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){count++;
        }

    }
    path.pop_back();

   }

int sum(Node* root,int k){
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    int k=5;
   int satya=sum(root,k);
   cout<<"k sum path: "<<satya<<endl;
    return 0;
}