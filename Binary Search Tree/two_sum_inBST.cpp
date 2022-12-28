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

bool isPresent(Node* root, int k){
    vector<int> arr;
    inOrder(root, arr);

    int s = 0; int e = arr.size()-1;
    while(s<e){
        int sum = arr[s]+arr[e];
        if(sum == k)
            return true;
        else if(sum>k)   e--;
        else if(sum<k)   s++;
    }

    return false;
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    cout<<"The value of target is:- ";
    int k;  cin>>k;

    if(isPresent(root, k))
        cout<<"The target sum "<<k<<" is present in the BST"<<endl;
    else
        cout<<"The target sum "<<k<<" is not present in the BST"<<endl;

 return 0;
}