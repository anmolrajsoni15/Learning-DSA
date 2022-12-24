// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes.

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

node* lca(node* root, int n1, int n2){
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;
    else if(left != NULL && right == NULL)
        return left;
    else if(left == NULL && right != NULL)
        return right;
    else    return NULL;
}


int main(){
    node* root = NULL;
    root = buildTree(root);

    node* temp = lca(root, 17, 11);
    cout<<"The lowest comman ancestor of 17 and 11 is:- ";
    cout<<temp->data<<endl;
 return 0;
}