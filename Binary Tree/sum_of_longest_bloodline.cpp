//Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)

#include<bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   / 
       7   11 17  

    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
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

void solve(node* root, int len, int &maxlen, int sum, int &maxsum){
    if(root == NULL){
        if(len>maxlen){
            maxlen = len;
            maxsum = sum;
        }
        else if(len == maxlen){
            maxsum = max(maxsum, sum);
        }
        return;
    }

    sum += root->data;

    solve(root->left, len+1, maxlen, sum, maxsum);
    solve(root->right, len+1, maxlen, sum, maxsum);
}

void longestSum(node* root){
    int len = 0, maxlen = 0, sum = 0, maxsum = 0;
    solve(root, len, maxlen, sum, maxsum);
    cout<<maxsum<<endl;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"The maxsum of longest root to leaf length is:- ";
    longestSum(root);
 return 0;
}