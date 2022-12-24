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

int height(node* root){
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right)+1;
}

//brute force 
//time complexity:- O(n^2)
int diameter(node* root){
    if(root == NULL)
        return 0;

    int d1 = diameter(root->left);
    int d2 = diameter(root->right);
    int d3 = height(root->left)+height(root->right)+1;

    return max({d1, d2, d3});
}

//optimised approach
//time complexity: O(n)
pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int d1 = left.first;
    int d2 = right.first;
    int d3 = left.second+right.second+1;

    pair<int, int> ans;
    ans.first = max({d1, d2, d3});
    ans.second = max(left.second, right.second)+1;

    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<endl<<"The diameter of the tree is:- ";
    cout<<diameter(root)<<endl;
    cout<<"The diameter of tree in optimised way is:- ";
    cout<<diameterFast(root).first<<endl;
 return 0;
}