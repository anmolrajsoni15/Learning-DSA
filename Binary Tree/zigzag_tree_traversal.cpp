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

vector<int> zigZagTraversal(node* root){
    vector<int> result;
    if(root == NULL)
        return result;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        //level process
        for(int i = 0; i<size; i++){
            node* frontNode = q.front();
            q.pop();

            //insertion
            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }

        //direction change
        leftToRight = !leftToRight;

        for(auto it: ans)
            result.push_back(it);
    }

    return result;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    ans = zigZagTraversal(root);

    cout<<endl<<"Zig-Zag traversal of a tree is:-"<<endl;
    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;

 return 0;
}