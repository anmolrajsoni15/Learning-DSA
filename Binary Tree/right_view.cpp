//top view of a binary tree
#include<bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   / 
       7   11 17  

    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
*/

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;   cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

void solve(node* root, vector<int> &ans, int level){
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}

void rightView(node* root){
    vector<int> ans;
    solve(root, ans, 0);
    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"The right view of the given tree is:- "<<endl;
    rightView(root);
 return 0;
}