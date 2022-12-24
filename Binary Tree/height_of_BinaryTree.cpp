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

int height(node* root){
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right)+1;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"The height of the tree is:- ";
    cout<<height(root)<<endl;
 return 0;
}