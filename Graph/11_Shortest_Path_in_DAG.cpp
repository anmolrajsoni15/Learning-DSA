#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<pair<int, int>>> &adj, stack<int> &s){
    vis[node] = true;

    for(auto nbgh : adj){
        if(!vis[nbgh.first])
            dfs(nbgh.first, vis, adj, s);
    }

    s.push(node);
}

vector<int> getShortestPath(int src, vector<vector<int>> &edges, int n){
    //create adjacency list for Directed Graph
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
    }

    //get the topological sorted array;
    unordered_map<int, bool> visited;
    stack<int> st;

    for(int i = 0; i<n; i++){
        if(!visited[i])
            dfs(i, visited, adj, st);
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(dist[top] != INT_MAX){
            for(auto i : adj[top]){
                if(dist[top]+i.second < dist[i.first]){
                    dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }

    return dist;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the graph  ";
    cin>>n;

    vector<vector<int>> edges;
    cout<<"How many edges are there:- ";
    int e;  cin>>e;
    for(int i = 0; i<e; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        edges.push_back({x, y, w});
    }

    int src;
    cout<<"Enter the source node:- ";
    cin>>src;

    vector<int> ans = getShortestPath(src, edges, n);
    cout<<"The shortest distance of all the nodes from source node are:-\n";
    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
    
 return 0;
}