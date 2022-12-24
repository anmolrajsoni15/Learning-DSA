#include<iostream>
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

int main(){
    node *root = NULL;

    //building a tree
    buildTree(root);
 return 0;
}