#include<iostream>
#include<queue>
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

Node* insertIntoBST(int data, Node* root){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(data, root->right);
    }
    else
        root->left = insertIntoBST(data, root->left);

    return root;
}

void takeInput(Node* &root){
    int data;   cin>>data;
    while(data != -1){
        root = insertIntoBST(data, root);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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
}

int main(){

    Node* root = NULL;
    cout<<"Enter the datas to create BST"<<endl;
    takeInput(root);
    cout<<"Your BST is:-"<<endl;
    levelOrderTraversal(root);

 return 0;
}