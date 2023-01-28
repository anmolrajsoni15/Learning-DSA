#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    void makeSet(vector<int> &parent, vector<int> &rank, int n){
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

int main(){
    int n;
    cout<<"No of nodes = ";
    cin>>n;
    vector<int> parent(n), rank(n);

    DSU d;
    d.makeSet(parent, rank, n);    
    d.UnionSets(0, 1, parent, rank);
    d.UnionSets(2, 3, parent, rank);
    d.UnionSets(4, 5, parent, rank);
    d.UnionSets(3, 4, parent, rank);
    d.UnionSets(1, 5, parent, rank);

    cout<<"After Union the parent array looks like:- \n";
    for(int i = 0; i<n; i++)
        cout<<parent[i]<<' ';
    cout<<endl;

 return 0;
}