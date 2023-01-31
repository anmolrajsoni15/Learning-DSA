#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solve(vector<int> &cost, int n){
    if(n == 0)
        return cost[0];
    if(n == 1)
        return cost[1];

    return cost[n]+min(solve(cost, n-1), solve(cost, n-2));
}

int minCost(vector<int> &cost){
    int n = cost.size();
    return min(solve(cost, n-1), solve(cost, n-2));
}

//using memoization
int solve2(vector<int> &cost, int n, vector<int> &dp){
    if(n == 0)
        return cost[0];
    if(n == 1)
        return cost[1];

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = cost[n]+min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
}

int minCostMemo(vector<int> &cost){
    int n = cost.size();
    vector<int> dp(n+1, -1);
    return min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
}

//using tabulation
int solve3(vector<int> &cost, int n){
    vector<int> dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i<n; i++)
        dp[i] = cost[i]+min(dp[i-1], dp[i-2]);

    return min(dp[n-1], dp[n-2]);
}

//using space optimisation
int solve4(vector<int> &cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i<n; i++){
        int curr = cost[i]+min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev2, prev1);
}

int main(){
    int n;
    cout<<"Enter the size of cost array:- ";
    cin>>n;

    vector<int> cost(n);
    cout<<"Enter the values for cost array:-\n";
    for(int i = 0; i<n; i++)
        cin>>cost[i];

    //recursive approach
    cout<<"Minimum cost to reach nth stair is:- "<<minCost(cost)<<endl;

    //using dp
    //using memoization
    cout<<"Minimum cost to reach nth stair is:- "<<minCostMemo(cost)<<endl;

    //using tabulation
    cout<<"Minimum cost to reach nth stair is:- "<<solve3(cost, cost.size())<<endl;
    
    //using space optimisation
    cout<<"Minimum cost to reach nth stair is:- "<<solve4(cost, cost.size())<<endl;

 return 0;
}