#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        int row;
        int col;

    node(int d, int i, int j){
        data = d;
        row = i;
        col = j;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArray(vector<vector<int>> arr, int k){
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(int i = 0; i<k; i++){
        node* temp = new node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    while(!minHeap.empty()){
        node* top = minHeap.top();
        minHeap.pop();  
        ans.push_back(top->data);

        int i = top->row;
        int j = top->col;

        if(j+1 < arr[i].size()){
            node* next = new node(arr[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main(){
    int r, c;
    cout<<"Enter the number of arrays and size of each array:- ";
    cin>>r>>c;

    cout<<"Enter the arrays\n";
    vector<vector<int>> arr(r, vector<int>(c));
    for(int i = 0; i<r; i++)
        for(int j = 0; j<c; j++)
            cin>>arr[i][j];

    vector<int> sortedArray = mergeKArray(arr, r);
    cout<<"The overall sorted array is :- \n";
    for(int i : sortedArray)
        cout<<i<<' ';
    cout<<endl;

 return 0;
}