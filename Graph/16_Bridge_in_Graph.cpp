#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int p, int t, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<vector<int>> &res){
    vis[node] = true;

    disc[node] = low[node] = t++;

    for(auto nbgh: adj[node]){
        if(nbgh == p)
            continue;

        if(!vis[nbgh]){
            dfs(nbgh, node, t, disc, low, vis, adj, res);
            low[node] = min(low[node], low[nbgh]);
            //check edge is a bridge
            if(low[nbgh] > disc[node]){
                vector<int> temp;
                temp.push_back(node);
                temp.push_back(nbgh);
                res.push_back(temp);
            }
        }
        else{
            //back edge
            low[node] = min(low[node], disc[nbgh]);
        }
    }
}

vector<vector<int>> bridges(vector<pair<int, int>> edges, int n){
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

    vector<vector<int>> res;
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

    vector<vector<int>> ans = bridges(edges, n);

    cout<<"All the bridges in the graphs are:- \n";
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
 return 0;
}