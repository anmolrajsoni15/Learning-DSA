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

class info{
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
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

info solve(Node* root, int &ans){
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        currNode.isBST = true;
    else    currNode.isBST = false;

    if(currNode.isBST)
        ans = max(ans, currNode.size);

    return currNode;
}

int maxBST(Node* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main(){
    Node* root = NULL;
    cout<<"Enter Data to build Binary tree:-\n";
    root = buildTree(root);

    cout<<"The size of largest Binary subtree which is BST is:- "<<maxBST(root)<<endl;
 return 0;
}