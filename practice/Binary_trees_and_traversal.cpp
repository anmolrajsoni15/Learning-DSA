#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    int data;
    // cout<<"Enter the data:- ";
    cin>>data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    // cout<<"Enter data to left of "<<data<<endl;
    root->left = buildTree(root->left);
    // cout<<"Enter data to right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
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

void InOrder(Node* root){
    if(root == NULL)
        return;
    
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PreOrder(Node* root){
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root){
    if(root == NULL)
        return;
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
Node* root = NULL;

    cout<<"Enter the datas"<<endl;
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<"\n\nYour Tree looks somewhat likethis\n";
    levelOrderTraversal(root);
    
    cout<<"\n \n\tThe data according to inorder traversal is\n\t\t";
    InOrder(root);
    cout<<"\n \n\tThe data according to preorder traversal is\n\t\t";
    PreOrder(root);
    cout<<"\n \n\tThe data according to postorder traversal is\n\t\t";
    PostOrder(root);
 return 0;
}