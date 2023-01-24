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

Node* buildTree(Node* root){
    int data;   cin>>data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

int countNodes(Node* root){
    if(root == NULL)    return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

bool isCBT(int i, Node* root, int n){
    if(root == NULL)
        return true;
    if(i >= n)
        return false;
    else{
        bool left = isCBT(2*i+1, root->left, n);
        bool right = isCBT(2*i+2, root->right, n);
        return (left && right);
    }
}

bool isMaxOrder(Node* root){
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->right == NULL)
        return (root->data > root->left->data);
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
}

//here heap is reffered as maxHeap
bool isHeap(Node* root){
    int index = 0;
    int size = countNodes(root);
    
    if(isCBT(index, root, size) && isMaxOrder(root))
        return true;
    else    return false;
}

int main(){
    cout<<"Enter the data for tree:-\n";

    Node* root = NULL;
    root = buildTree(root);

    if(isHeap(root))
        cout<<"\nThe given tree is a Heap(Max-Heap)\n";
    else
        cout<<"\nThe given tree is not Heap(Max-Heap)\n";
 return 0;
}