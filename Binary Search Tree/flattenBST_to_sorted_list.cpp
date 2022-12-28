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

void inOrder(Node* root, vector<int> &arr){
    if(root == NULL)    return;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node* flatten(Node* root){
    vector<int> arr;
    inOrder(root, arr);

    Node* newNode = new Node(arr[0]);
    Node* curr = newNode;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newNode;
}

void printFlattenTree(Node* root){
    if(root == NULL)
        return;

    cout<<root->data<<' ';
    printFlattenTree(root->right);
}


int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    Node* newNode = flatten(root);
    cout<<"The Flatten Sorted List of given BST is:- \n";
    printFlattenTree(newNode);
 return 0;
}