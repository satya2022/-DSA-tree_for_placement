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
bool isidentical(Node *root1,Node *root2) {
    //base case 
    if(root1==NULL&&root2==NULL) 
    {return true;}
    if(root1!=NULL&&root2==NULL) 
    {return false;}
    if(root1==NULL&&root2!=NULL) 
    {return false;}
    bool left=isidentical(root1->left,root2->left);
    bool right=isidentical(root1->left,root2->left);
    bool value=root1->data==root2->data;
    if(left&&right&&value){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    // bilding tree
    root1 = buildTree(root1);
    cout<<"now we print take input value of second tree"<<endl;
    root2 = buildTree(root2);
    cout<<"kya isidentical hai"<<isidentical<<endl;
    return 0;
}