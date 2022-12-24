#include<bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   / 
       7   11 17  
*/

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    // cout<<"Enter the data:- ";
    int data;   cin>>data;

    root = new Node(data);

    if(data == -1)
        return NULL;
    // cout<<"Enter data for left Node of "<<data<<" :- "<<endl;
    root->left = buildTree(root->left);
    // cout<<"Enter data for right Node of "<<data<<" :- "<<endl;
    root->right = buildTree(root->right);

    return root;

}

bool isBST(Node *root, int mini, int maxi){
    if(root == NULL)
        return true;
    if(root->data > mini && root->data < maxi){
        bool left = isBST(root->left, mini, root->data);
        bool right = isBST(root->right, root->data, maxi);
        return left && right;
    }
    else return false;
}

bool validate(Node* root) 
{
    // Your code here
    return isBST(root, INT_MIN, INT_MAX);
}

void inOrder(Node* root){
    if(root == NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<' ';
    inOrder(root->right);
}

int main(){
    Node *root = NULL;

    //building a tree
    root = buildTree(root);
    inOrder(root);
    cout<<endl;

    if(validate(root))
        cout<<"The tree is a Balanced BST"<<endl;
    else
        cout<<"The tree is not a BST"<<endl;
 return 0;
}