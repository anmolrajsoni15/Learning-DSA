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

void linearLevelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    cout<<endl;
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void perorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    perorder(root->left);
    perorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root = NULL;

    //building a tree
    root = buildTree(root);
    cout<<endl<<"Level Order Traversal whithout pattern"<<endl;
    linearLevelOrderTraversal(root);
    cout<<"Level Order Traversal with pattern"<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder Traversal:- "<<endl;
    inorder(root);
    cout<<endl<<"Preorder Traversal:- "<<endl;
    perorder(root);
    cout<<endl<<"Postorder Traversal:- "<<endl;
    postorder(root);
 return 0;
}