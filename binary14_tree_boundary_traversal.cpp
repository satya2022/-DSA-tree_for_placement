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
    // base case
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

void traverseLeft(Node *root,vector<int>&ans){
    //base  case 
    if(root==NULL){return;}
    if(root->left==NULL&&root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
    traverseLeft(root->left,ans);
    }
    else{
    traverseLeft(root->right,ans);
    }
}


void traverseRight(Node *root,vector<int>&ans){
    //base  case 
    if(root==NULL){return;}
    if(root->left==NULL&&root->right==NULL){
        return;
    }
    if(root->right){
    traverseRight(root->right,ans);
    }
    else{
    traverseRight(root->left,ans);
    }
    //tree k right side bala ko reverse karke print krna hai
    ans.push_back(root->data);

}

void traverseLefe(Node *root,vector<int>&ans){
    //base case
    if(root==NULL){return;}
    //2 nd base case
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLefe(root->left,ans);
    traverseLefe(root->right,ans);

}


vector<int> boundry(Node* root) {
    vector<int>ans;
    if(root==NULL) {return ans;}

    ans.push_back(root->data);
    //left part print/store
    //Traverse left part
    traverseLeft(root->left, ans);

    //traverse lefe Node
    //lefesubtree
    traverseLefe(root->left, ans);
    //traverse lefe Node Rightsubtree
    traverseLefe(root->right, ans);

//traverse right part print/store
traverseRight(root->right, ans);

return ans;  

}


int main()
{
    Node *root = NULL;
    // bilding tree
    root = buildTree(root);
    /*
std::vector<char> path;
// ...
for (char i: path)
 std::cout << i << ' ';
    */

  vector <int> res =boundry(root);
      cout<<"boundry traversal of binary tree is:"<<endl;
    for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
    cout<<endl;
}