#include<iostream>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   / 
       7   11 17  

    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
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

pair<bool, int> sumVal(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = sumVal(root->left);
    pair<bool, int> right = sumVal(root->right);

    bool isLeft = left.first;
    bool isRight = right.first;
    bool sum = root->data == left.second+right.second;

    pair<bool, int> ans;

    if(isLeft && isRight && sum){
        ans.second = 2*root->data;
        ans.first = true;
    }
    else{
        ans.second = false;
    }

    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    if(sumVal(root).first)
        cout<<"The tree is a sumtree."<<endl;
    else
        cout<<"The tree is not a sumtree."<<endl;

 return 0;
}