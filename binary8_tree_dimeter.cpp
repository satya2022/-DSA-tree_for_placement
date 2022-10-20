#include <bits\stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // construct
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildtree(Node *root)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    // base case
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data on left of data" << data << endl;
    root->left = buildtree(root->left);
    cout << "enter data on right of data" << data << endl;
    root->right = buildtree(root->right);
    return root;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

pair<int, int>dimeterFaster(Node *root){
//base case 
if(root==NULL){
    pair<int, int>p=make_pair(0,0);
    return p;
}
//in <int,int>  first int=contain dimeter  and second int=contain height
pair<int, int>left=dimeterFaster(root->left);
pair<int, int>right=dimeterFaster(root->right);
int op1=left.first;
int op2=right.first;
int op3=left.second+right.second+1;
pair<int, int>ans;
ans.first=max(op1,max(op2,op3));
//height
ans.second=max(left.second,right.second)+1;
return ans;
}

int dimeter(Node *root)
{
return dimeterFaster(root).first;
}
int main()
{
    Node *root = NULL;
    root = buildtree(root);
    cout << "height is" << height(root) << endl;
    cout << "width is" << dimeter(root) << endl;
}