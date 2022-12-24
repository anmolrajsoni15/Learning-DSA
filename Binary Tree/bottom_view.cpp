//top view of a binary tree
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

void topView(node* root){
    vector<int> ans;
    if(root == NULL){
        cout<<"The tree is empty";
        return;
    }

    map<int, int> mp;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        mp[hd] = frontNode->data;
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));
    }

    for(auto it: mp)
        ans.push_back(it.second);

    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"The bottom view of the given tree is:- "<<endl;
    topView(root);
 return 0;
}