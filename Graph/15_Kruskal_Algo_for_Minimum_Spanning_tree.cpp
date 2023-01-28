#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    DSU(vector<int> &parent, vector<int> &rank, int n){
        for(int i = 0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findParent(vector<int> &parent, int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent, parent[node]);
    }

    void UnionSets(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u])
            parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
};

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int minSpanningTree(vector<vector<int>> &edges, int n){
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n);
    DSU d(parent, rank, n);

    int minWeight = 0;
    for(int i = 0; i<edges.size(); i++){
        int u = d.findParent(parent, edges[i][0]);
        int v = d.findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if(u != v){
            minWeight += w;
            d.UnionSets(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main(){
    int n;
    cout<<"No of nodes = ";
    cin>>n;

    int e;
    cout<<"Enter the number of edges:- ";
    cin>>e;
    vector<vector<int>> edges(e, vector<int>(3));
    cout<<"Create the edges with their weight\n";
    for(int i = 0; i<e; i++){
        for(int j = 0; j<3; j++){
            cin>>edges[i][j];
        }
    }

    cout<<"The minimum weight of minimum spanning tree is :-  ";
    cout<<minSpanningTree(edges, n);
    

 return 0;
}