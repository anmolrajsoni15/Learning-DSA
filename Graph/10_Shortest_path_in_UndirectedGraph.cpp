#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int s, int e){

    //create adjacency list
    unordered_map<int, list<int>> adj;
    for(auto it: edges){
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto nbgh: adj[front]){
            if(!visited[nbgh]){
                visited[nbgh] = true;
                parent[nbgh] = front;
                q.push(nbgh);
            }
        }
    }

    vector<int> ans;
    int curr = e;
    ans.push_back(e);

    while(curr != s){
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());

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

    int s, e;
    cout<<"Choose your starting and ending point:- ";
    cin>>s>>e;

    vector<int> ans = shortestPath(edges, n, s, e);
    cout<<"The sortest path between "<<s<<"and "<<e<<" is:-\n";
    for(auto it: ans)
        cout<<it<<' ';
    cout<<endl;
        
 return 0;
}