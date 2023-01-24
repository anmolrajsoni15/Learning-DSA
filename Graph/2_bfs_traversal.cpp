#include<bits/stdc++.h>
using namespace std;

void createAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for(auto it: adj[front]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
    
}

vector<int> BFS(int V, vector<pair<int, int>> edges){
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> ans;

    createAdjList(adj, edges);

    for(int i = 0; i<V; i++){
        if(!visited[i])
            bfs(adj, visited, ans, i);
    }

    return ans;
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

    vector<int> ans = BFS(n, edges);
    cout<<"The BFS traversal of graph is:-\n";
    for(auto i : ans)
        cout<<i<<' ';
    cout<<endl;

 return 0;
}