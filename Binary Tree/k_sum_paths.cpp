// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.

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

void solve(node* root, int k, int &cnt, vector<int> box){
    if(root == NULL)
        return;

    box.push_back(root->data);

    solve(root->left, k, cnt, box);
    solve(root->right, k, cnt, box);

    int sum = 0;
    for(int i = box.size()-1; i>=0; i--){
        sum += box[i];
        if(sum == k)
            cnt++;
    }

    box.pop_back();
}

int kSum(node* root, int k){
    int cnt = 0;
    vector<int> box;
    solve(root, k, cnt, box);

    return cnt;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"Enter the value of k"<<endl;
    int k;  cin>>k;
    cout<<"Number of paths in tree with value of k as "<<k<<" is "<<kSum(root, k)<<endl;
 return 0;
}