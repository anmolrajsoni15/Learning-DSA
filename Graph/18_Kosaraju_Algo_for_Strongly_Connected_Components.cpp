#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj){
    vis[node] = true;

    for(auto nbgh: adj[node]){
        if(!vis[nbgh])
            dfs(nbgh, vis, st, adj);
    }

    //topo sorted array
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj){
    vis[node] = true;

    for(auto nbgh: adj[node]){
        if(!vis[nbgh])
            revDfs(nbgh, vis, adj);
    }
}

int stronglyConnectedComp(vector<pair<int, int>> &edges, int n){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 0; i<n; i++){
        if(!visited[i])
            dfs(i, visited, st, adj);
    }

    unordered_map<int, list<int>> trans;
    for(int i = 0; i<n; i++){
        visited[i] = false;
        for(auto nbh: adj[i])
            trans[nbh].push_back(i);
    }

    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(!visited[top]){
            count++;
            revDfs(top, visited, trans);
        }
    }

    return count;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the graph  ";
    cin>>n;

    vector<pair<int, int>> edges;
    cout<<"How many edges are there:- ";
    int e;  cin>>e;
    for(int i = 0; i<e; i++)
    {
        int x, y;
        cin>>x>>y;
        edges.push_back({x, y});
    }

    cout<<"Number of strongly connected components are:- ";
    cout<<stronglyConnectedComp(edges, n)<<endl;
 return 0;
}