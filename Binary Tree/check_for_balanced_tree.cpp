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
bool isBalanced(node* root){
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left)-height(root->right)) <= 1;

    if(left && right && diff)
        return true;
    else
        return false;
}

//optimised approach
//time complexity: O(n)
pair<bool, int> isBalancedFast(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second-right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second)+1;

    if(leftAns && rightAns && diff)
        ans.first = true;
    else    ans.first = false;

    return ans;
}


int main(){
    node* root = NULL;
    root = buildTree(root);
    bool check = isBalanced(root);
    if(check)
        cout<<"The tree is Balanced"<<endl;
    else
        cout<<"The tree is not Balanced"<<endl;

    bool checkFast = isBalancedFast(root).first;
    if(checkFast)
        cout<<"The tree is Balanced"<<endl;
    else
        cout<<"The tree is not Balanced"<<endl;
 return 0;
}