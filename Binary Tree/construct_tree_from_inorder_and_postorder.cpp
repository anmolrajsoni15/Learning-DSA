#include<bits/stdc++.h>
using namespace std;

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

void createMapping(map<int, int> &mp, vector<int> &in, int n){
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;
}

node* solve(map<int, int> &mp, vector<int> &in, vector<int> &post, int n, int &index, int start, int end){
    if(index >= n || start>end)
        return NULL;

    int element = post[index--];
    int position = mp[element];
    node* root = new node(element);

    root->right = solve(mp, in, post, n, index, position+1, end);
    root->left = solve(mp, in, post, n, index, start, position-1);

    return root;
}

node* buildTree(vector<int> &in, vector<int> &post, int n){
    map<int, int> mapping;
    createMapping(mapping, in, n);
    int postInd = n-1;

    node* ans = solve(mapping, in, post, n, postInd, 0, n-1);
    return ans;
}

void preorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    cout<<"Enter no. of elements:- ";
    int n;  cin>>n;

    vector<int> post, in;
    cout<<"Enter the InOrder traversal of a tree \n";
    for (int i = 0; i < n; i++)
    {
        int x;  cin>>x;
        in.push_back(x);
    }

    cout<<"Enter the PostOrder traversal of a tree \n";
    for (int i = 0; i < n; i++)
    {
        int x;  cin>>x;
        post.push_back(x);
    }
    
    node* root = buildTree(in, post, n);

    cout<<"Hence after construction of a tree, it's preOrder traversal is:-"<<endl;
    preorder(root);
 return 0;
}