#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    int row;
    int col;

    node(int n, int i, int j){
        val = n;
        row = i;
        col = j;
    }
};

class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->val > b->val;
    }
};

pair<int, int> smallestRange(vector<vector<int>> nums){
    priority_queue<node*, vector<node*>, cmp> minHeap;

    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i<nums.size(); i++){
        mini = min(mini, nums[i][0]);
        maxi = max(maxi, nums[i][0]);
        minHeap.push(new node(nums[i][0], i, 0));
    }

    int first = mini, last = maxi;
    while(!minHeap.empty()){
        auto top = minHeap.top();
        minHeap.pop();

        mini = top->val;
        if(maxi-mini < last-first){
            first = mini;
            last = maxi;
        }

        if(top->col+1 < nums[top->row].size()){
            maxi = max(maxi, nums[top->row][top->col+1]);
            minHeap.push(new node(nums[top->row][top->col+1], top->row, top->col+1));
        }
        else    break;
    }

    pair<int, int> ans = {first, last};
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the matrix:- ";
    cin>>n;
    vector<vector<int>> nums(n, vector<int>(n));
    cout<<"Enter the data\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>nums[i][j];
        }
    }

    pair<int, int> ans = smallestRange(nums);
    cout<<"Smallest range that contains atleast one element from each row is:- ";
    cout<<ans.first<<" - "<<ans.second<<endl;

 return 0;
}