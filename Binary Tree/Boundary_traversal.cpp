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

void traverseLeft(node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    
    ans.push_back(root->data);
    if(root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(node* root, vector<int> &ans){
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node* root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    
    if(root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(node* root){
    vector<int> ans;
    if(root == NULL)
        return  ans;
    
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);

    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    ans = boundary(root);

    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;

 return 0;
}