#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> getShortestPath(vector<vector<int>> &edges, int n){
    //create adjacency list for Weighted Undirected Graph
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX);    //an array that stores the minimum distance 
    vector<bool> mst(n, false);     // an array that checks for mst
    vector<int> parent(n, -1);      // an array that keeps track of parent node

    key[0] = 0;     //initial distance of root node set to 0
    parent[0] = -1;     //parent of root is -1

    //iterate through every edges
    for(int i = 0; i<n; i++){
        int mini = INT_MAX;
        int u;

        //get the current minimum if mst is false and it is minimum
        //this process can be optimised by using priority queue(minHeap)
        for(int j = 0; j<n; j++){
            if(mst[j] == false && key[j] < mini){
                u = j;
                mini = key[j];
            }
        }

        mst[u] = true;  //set that minimum value true

        //check for adjacent nodes and set their parent and minimum weights
        for(auto nbgh : adj[u]){
            if(mst[nbgh.first] == false && nbgh.second < key[nbgh.first]){
                parent[nbgh.first] = u;
                key[nbgh.first] = nbgh.second;
            }
        }
    }

    //return the ans as (parent, node, weight)
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 1; i<n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
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

    vector<pair<pair<int, int>, int>> ans;
    
 return 0;
}