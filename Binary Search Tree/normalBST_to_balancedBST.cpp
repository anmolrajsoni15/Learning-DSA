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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<front->data<<' ';
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }

    }
    cout<<endl;
}

void inOrder(Node* root, vector<int> &arr){
    if(root == NULL)    return;

    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

Node* makeItBalanced(vector<int> &arr, int s, int e){
    if(s>e) return NULL;

    int mid = s+(e-s)/2;
    Node* temp = new Node(arr[mid]);
    temp->left = makeItBalanced(arr, s, mid-1);
    temp->right = makeItBalanced(arr, mid+1, e);

    return temp;
}

Node* balancedBST(Node* root){
    vector<int> arr;
    inOrder(root, arr);

    return makeItBalanced(arr, 0, arr.size()-1);
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    cout<<"\n The new Balanced BST is:- \n";
    Node* newNode = balancedBST(root);
    levelOrderTraversal(newNode);
 return 0;
}