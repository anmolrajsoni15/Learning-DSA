#include<bits/stdc++.h>
using namespace std;

vector<int> getShortestPath(int src, vector<vector<int>> &edges, int n){
    //create adjacency list for Weighted Undirected Graph
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    //create distance array and set the distance of source as 0
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    //create a set with comprising (distance, node);
    set<pair<int, int>> st;
    st.insert({0, src});

    while(!st.empty()){
        auto top = *(st.begin());
        int dst = top.first;
        int node = top.second;

        st.erase(st.begin());

        for(auto nbgh : adj[node]){
            if(dst + nbgh.second < dist[nbgh.first]){
                auto rcd = st.find({dist[nbgh.first], nbgh.first});
                if(rcd != st.end())
                    st.erase(rcd);

                dist[nbgh.first] = dst + nbgh.second;
                st.insert({dist[nbgh.first], nbgh.first});
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