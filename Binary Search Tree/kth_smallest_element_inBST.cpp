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

int solve(Node *root, int K, int &cnt){
    if(root == NULL)
        return -1;
        
    int left = solve(root->left, K, cnt);
    if(left != -1)
        return left;
        
    cnt++;
    if(cnt == K){
        return root->data;
    }
    
    return solve(root->right, K, cnt);
}

int KthSmallestElement(Node *root, int K) {
    int i = 0;
    return solve(root, K, i);
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);

    cout<<"Enter the value of K to find Kth smallest element\n";
    int k;  cin>>k;

    int ans = KthSmallestElement(root, k);
    if(ans != -1){
        cout<<"The Kth smallest element in the BST is = "<<ans<<endl;
    }
    else{
        cout<<"The element does not exist in the BST"<<endl;
    }
 return 0;
}