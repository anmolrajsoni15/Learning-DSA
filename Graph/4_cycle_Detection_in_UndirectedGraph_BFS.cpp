#include<bits/stdc++.h>
using namespace std;

bool isCyclePresent(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited){
    unordered_map<int, int> parent;
    visited[node] = true;
    parent[node] = -1;

    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto nbgh: adj[node]){
            if(visited[nbgh] && nbgh != parent[front])
                return true;
            else if(!visited[nbgh]){
                visited[nbgh] = true;
                q.push(nbgh);
                parent[nbgh] = front;
            }
        }
    }

    return false;
    
}

bool cycleDetectionBFS(vector<pair<int, int>> &edges, int v){
    unordered_map<int, list<int>> adj;

    for(auto it: edges){
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            bool ans = isCyclePresent(i, adj, visited);
            if(ans) return ans;
        }
    }

    return false;
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

    if(cycleDetectionBFS(edges, n))
        cout<<"Cycle is present in the graph\n";
    else    cout<<"No cycle present!!\n";
 return 0;
}