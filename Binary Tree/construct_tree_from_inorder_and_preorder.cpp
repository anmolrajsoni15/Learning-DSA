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

node* solve(map<int, int> &mp, vector<int> &in, vector<int> &pre, int n, int &index, int start, int end){
    if(index >= n || start>end)
        return NULL;

    int element = pre[index++];
    int position = mp[element];
    node* root = new node(element);

    root->left = solve(mp, in, pre, n, index, start, position-1);
    root->right = solve(mp, in, pre, n, index, position+1, end);

    return root;
}

node* buildTree(vector<int> &in, vector<int> &pre, int n){
    map<int, int> mapping;
    createMapping(mapping, in, n);
    int preInd = 0;

    node* ans = solve(mapping, in, pre, n, preInd, 0, n-1);
    return ans;
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    cout<<"Enter no. of elements:- ";
    int n;  cin>>n;

    vector<int> pre, in;
    cout<<"Enter the InOrder traversal of a tree \n";
    for (int i = 0; i < n; i++)
    {
        int x;  cin>>x;
        in.push_back(x);
    }

    cout<<"Enter the PreOrder traversal of a tree \n";
    for (int i = 0; i < n; i++)
    {
        int x;  cin>>x;
        pre.push_back(x);
    }
    
    node* root = buildTree(in, pre, n);

    cout<<"Hence after construction of a tree, it's postOrder traversal is:-"<<endl;
    postorder(root);
 return 0;
}