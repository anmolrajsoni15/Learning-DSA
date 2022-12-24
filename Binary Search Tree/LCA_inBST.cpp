#include<bits/stdc++.h>
using namespace std;

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

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data)
        root->right = insertIntoBST(root->right, d);
    if(d < root->data)
        root->left = insertIntoBST(root->left, d);

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }

    if(data == -1)  return;
}

Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
        
    if(root->data>n1 && root->data>n2)
        return LCA(root->left,n1,n2);

    if(root->data<n1 && root->data<n2)
        return LCA(root->right,n1,n2);

   return root;
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    Node* Lca = LCA(root, 7, 9);
    cout<<"LCA of 7 and 9 in BST is "<<Lca->data<<endl;
 return 0;
}