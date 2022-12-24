#include <bits/stdc++.h>
using namespace std;

/*
             1
           /   \
          3     5
        /  \   /
       7   11 17

    1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

Node *createMapping(Node *root, int target, map<Node *, Node *> &mp)
{
    Node *res = NULL;

    queue<Node *> q;
    q.push(root);
    mp[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
            res = front;

        if (front->left)
        {
            mp[front->left] = front;
            q.push(front->left);
        }

        if (front->right)
        {
            mp[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int solve(Node *root, map<Node *, Node *> &mp)
{
    map<Node *, bool> visited;
    queue<Node *> q;

    q.push(root);
    visited[root] = 1;

    int ans = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if (mp[front] && !visited[mp[front]])
            {
                flag = 1;
                q.push(mp[front]);
                visited[mp[front]] = 1;
            }
        }

        if (flag)
            ans++;
    }
    return ans;
}

int minTime(Node *root, int target)
{
    /*
    Step-I : Create mapping of node with their parent
    Step-II : Find the target element in the tree
    Step-III : Burn the tree using BFS
    */
    map<Node *, Node *> mapping;
    Node *targetNode = createMapping(root, target, mapping);
    int ans = solve(targetNode, mapping);

    return ans;
}

int main()
{

    Node *root = NULL;
    root = buildTree(root);

    cout<<"Minimum time to burn the tree from node having data 3 is : "<<minTime(root, 3)<<endl;

    return 0;
}