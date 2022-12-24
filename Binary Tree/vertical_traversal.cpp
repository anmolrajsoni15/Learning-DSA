//vertical traversal of a binary tree
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

void verticalTraversal(node* root){
    map<int, map<int, vector<int>>> mp;
    queue<pair<node*, pair<int, int>>> q;
    vector<int> ans;

    if(root == NULL){
        cout<<"The tree is empty"<<endl;
        return;
    }

    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()){
        pair<node*, pair<int, int>> frontPart = q.front();
        q.pop();

        node* frontNode = frontPart.first;
        int hd = frontPart.second.first;
        int lvl = frontPart.second.second;

        mp[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    for(auto it: mp){
        for(auto jt: it.second){
            for(auto kt: jt.second){
                ans.push_back(kt);
            }
        }
    }

    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    cout<<"The vertical traversal of a binary tree is:- "<<endl;
    verticalTraversal(root);
 return 0;
}