#include<bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          2     3
        /  \   / 
       2   4  2 

    1 2 2 -1 -1 4 -1 -1 3 2 -1 -1 -1
*/

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;   cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}
node* solve(node* root, int &k, int num){
    if(root == NULL)
        return NULL;
    if(root->data == num)
        return root;
        
    node* left = solve(root->left, k, num);
    node* right = solve(root->right, k, num);
    
    if(left != NULL && right == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return left;
    }
    
    if(left == NULL && right != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return right;
    }
    
    return NULL;
}

int kthAncestor(node *root, int k, int num)
{
    node* ans = solve(root, k, num);
    if(ans == NULL || ans->data == num)
        return -1;
    else    ans->data;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"The 2nd ancestor of 4 is:-"<<endl;
    cout<<kthAncestor(root, 2, 4);
 return 0;
}