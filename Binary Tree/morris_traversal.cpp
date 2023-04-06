#include<bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   / 
       7   11 17  
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
    cout<<"Enter the data:- ";
    int data;   cin>>data;

    root = new node(data);

    if(data == -1)
        return NULL;

    cout<<"Enter data for left node of "<<data<<" :- "<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node of "<<data<<" :- "<<endl;
    root->right = buildTree(root->right);

    return root;
}

void morrisTraversalInorder(node* root){
    if(root == NULL)
        return;

    while(root != NULL){
        if(root->left == NULL){
            cout<<root->data<<' ';
            root = root->right;
        }
        else{
            node* pre = root->left;
            while(pre->right && pre->right != root){
                pre = pre->right;
            }

            if(pre->right == NULL){
                pre->right = root;
                root = root->left;
            }
            else{
                pre->right = NULL;
                cout<<root->data<<' ';
                root = root->right;
            }
        }
    }
}

void morrisTraversalPreorder(node* root){
    if(root == NULL)
        return;

    while(root != NULL){
        if(root->left == NULL){
            cout<<root->data<<' ';
            root = root->right;
        }
        else{
            node* pre = root->left;
            while(pre->right && pre->right != root){
                pre = pre->right;
            }

            if(pre->right == NULL){
                cout<<root->data<<' ';
                pre->right = root;
                root = root->left;
            }
            else{
                pre->right = NULL;
                root = root->right;
            }
        }
    }
}

int main(){
    node *root = NULL;

    //building a tree
    // 5 3 -1 -1 6 -1 -1
    root = buildTree(root);
    cout<<"The Inorder Morris Traversal of a tree is:-\n";
    morrisTraversalInorder(root);

    cout<<"The Preorder Morris Traversal of a tree is:-\n";
    morrisTraversalPreorder(root);
 return 0;
}