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
    cout << "enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    // base case
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data in left of" << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data in right of" << data << endl;
    root->right = buildTree(root->right);
    return root;
}


    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int> > > nodes;
        queue< pair<Node*, pair<int,int> > > q;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        }
        
        for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
int main()
{
    Node *root = NULL;
    root=buildTree(root);

    vector<int> res = verticalOrder(root);
    cout << "varticalorder traversal of binary tree is:" << endl;
    for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
    cout << endl;


  return 0;

}