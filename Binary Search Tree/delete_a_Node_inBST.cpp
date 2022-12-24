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

Node* minVal(Node* root){
    
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL)
        return root;

    if(root->data == val){
        // root has 0 child i.e. it is leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // root has 1 child
        // a) Left Child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // b) Right Child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //root has 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    }
    else if(root->data > val){
        root->left = deleteNode(root->left, val);
        return root;
    }
    else{
        root->right = deleteNode(root->right, val);
        return root;
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    cout<<"Hence the level order traversal of your BST is :- \n";
    levelOrderTraversal(root);

    cout<<endl;
    root = deleteNode(root, 20);
    cout<<"After deleting 20 from the BST the new BSt is:- \n";
    levelOrderTraversal(root);
 return 0;
}