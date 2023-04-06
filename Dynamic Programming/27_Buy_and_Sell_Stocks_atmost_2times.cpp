#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int ind, bool buy, vector<int> &prices, int k){
    if(ind == prices.size())
        return 0;
    if(k == 0)
        return 0;

    int profit = 0;
    if(buy){
        int take = -prices[ind] + solveRec(ind+1, false, prices, k);
        int notTake = solveRec(ind+1, true, prices, k);
        profit = max(take, notTake);
    }
    else{
        int take = prices[ind] + solveRec(ind+1, true, prices, k-1);
        int notTake = solveRec(ind+1, false, prices, k);
        profit = max(take, notTake);
    }

    return profit;
}

int maxProfitRec(vector<int>& prices) {
    return solveRec(0, true, prices, 2);
}

//using memoisation
int solveMemo(int ind, int buy, vector<int> &prices, int k, vector<vector<vector<int>>> &dp){
    if(ind == prices.size())
        return 0;
    if(k == 0)
        return 0;

    if(dp[ind][buy][k] != -1)
        return dp[ind][buy][k];

    int profit = 0;
    if(buy){
        int take = -prices[ind] + solveMemo(ind+1, 0, prices, k, dp);
        int notTake = solveMemo(ind+1, 1, prices, k, dp);
        profit = max(take, notTake);
    }
    else{
        int take = prices[ind] + solveMemo(ind+1, 1, prices, k-1, dp);
        int notTake = solveMemo(ind+1, 0, prices, k, dp);
        profit = max(take, notTake);
    }

    return dp[ind][buy][k] = profit;
}

int maxProfitMemo(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveMemo(0, 1, prices, 2, dp);
}

//using tabulation
int solveTab(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<2; buy++){
            for(int k = 1; k<=2; k++){
                int profit = 0;
                if(buy){
                    int take = -prices[ind] + dp[ind+1][0][k];
                    int notTake = dp[ind+1][1][k];
                    profit = max(take, notTake);
                }
                else{
                    int take = prices[ind] + dp[ind+1][1][k-1];
                    int notTake = dp[ind+1][0][k];
                    profit = max(take, notTake);
                }
                dp[ind][buy][k] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int maxProfitTab(vector<int>& prices) {
    return solveTab(prices);
}

//using space optimisation
int solveOpt(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));

    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<2; buy++){
            for(int k = 1; k<=2; k++){
                int profit = 0;
                if(buy){
                    int take = -prices[ind] + next[0][k];
                    int notTake = next[1][k];
                    profit = max(take, notTake);
                }
                else{
                    int take = prices[ind] + next[1][k-1];
                    int notTake = next[0][k];
                    profit = max(take, notTake);
                }
                curr[buy][k] = profit;
            }
        }
        next = curr;
    }

    return next[1][2];
}

int maxProfitOpt(vector<int>& prices) {
    return solveOpt(prices);
}

int main(){
    int n;
    cout<<"Size of array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the stocks price\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];
 return 0;
}