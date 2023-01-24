#include<bits/stdc++.h>
using namespace std;

bool cyclePresent(vector<pair<int, int>> &edges, int v){

    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(auto it: edges){
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //create indegrees
    vector<int> indegree(v);
    for(auto i : adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }
    
    //put all nodes with 0 indegrees into the queue
    queue<int> q;
    for(int i = 0; i<v; i++)
        if(indegree[i] == 0)
            q.push(i);

    //do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        cnt++;

        for(auto nbgh : adj[front]){
            indegree[nbgh]--;
            if(indegree[nbgh] == 0)
                q.push(nbgh);
        }
    }

    if(cnt == v)
        return false;
    else    return true;
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

    if(cyclePresent(edges, n))
        cout<<"The given Directed Graph is Cyclic"<<endl;
    else    cout<<"No cycle found !!!"<<endl;
        
 return 0;
}