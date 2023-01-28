#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int p, int t, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &res){
    vis[node] = true;

    disc[node] = low[node] = t++;
    int child = 0;
    for(auto nbgh: adj[node]){
        if(nbgh == p)
            continue;

        if(!vis[nbgh]){
            dfs(nbgh, node, t, disc, low, vis, adj, res);
            low[node] = min(low[node], low[nbgh]);
            //check AP or not
            if(low[nbgh] >= disc[node] && p != -1){
                res.push_back(node);
            }
            child++;
        }
        else{
            //back edge
            low[node] = min(low[node], disc[nbgh]);
        }
    }

    if(p == -1 && child > 1)
        res.push_back(node);
}

vector<int> ArticulationPoint(vector<pair<int, int>> edges, int n){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n, -1);
    int parent = -1;
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;

    vector<int> res;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, vis, adj, res);
        }
    }

    return res;
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

    vector<int> ans = ArticulationPoint(edges, n);

    cout<<"All the Articulation Points in the graphs is/are:- \n";
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }cout<<endl;
 return 0;
}