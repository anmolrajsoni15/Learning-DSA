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

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;   cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftNode;   cin>>leftNode;
        if(leftNode != -1){
            temp->left = new node(leftNode);
            q.push(temp->left);
        }

        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightNode;   cin>>rightNode;
        if(rightNode != -1){
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    cout<<endl;
}

int main(){
    node* root = NULL;
    buildFromLevelOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
 return 0;
}