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

Node* solve(vector<int> &preOrder, int mini, int maxi, int &i){
    if(i>=preOrder.size())
        return NULL;

    if(preOrder[i]<mini || preOrder[i]>maxi)
        return NULL;

    Node* root = new Node(preOrder[i++]);
    root->left = solve(preOrder, mini, root->data, i);
    root->right = solve(preOrder, root->data, maxi, i);

    return root;
}

Node* preOrderToBST(vector<int> &preOrder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preOrder, mini, maxi, i);
}


int main(){
    cout<<"-------PreOrder Traversal to BST-------\n\n";
    cout<<"Enter the number of nodes in a tree:- ";
    int n;  cin>>n;
    cout<<"Enter the preOrder traversal:-\n";
    vector<int> preOrder(n);
    for(int i = 0; i<n; i++)    cin>>preOrder[i];

    Node* root = preOrderToBST(preOrder);

    cout<<"BST from preOrder traversal is:- "<<endl;
    levelOrderTraversal(root);
 return 0;
}