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

pair<int, int> solve(node* root){
    if(root == NULL){
        pair<int, int> ans = make_pair(0, 0);
        return ans;
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return ans;
}

int getMaxSum(node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"Maximum non-adjacent sum of given nodes in a tree is ";
    cout<<getMaxSum(root)<<endl;
 return 0;
}