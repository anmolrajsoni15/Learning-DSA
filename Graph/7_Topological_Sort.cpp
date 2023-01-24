#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st){
    visited[node] = true;

    for(auto nbgh: adj[node])
        if(!visited[nbgh])
            topoSort(node, adj, visited, st);

    st.push(node);
}


vector<int> topologicalSort(vector<pair<int, int>> &edges, int v){
    unordered_map<int, list<int>> adj;

    for(auto it: edges){
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    stack<int> st;
    for(int i = 0; i<v; i++)
        if(!visited[i])
            topoSort(i, adj, visited, st);
            
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
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

    vector<int> ans = topologicalSort(edges, n);

    cout<<"The topological sort of given graph is:- \n";
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<' ';
        
 return 0;
}