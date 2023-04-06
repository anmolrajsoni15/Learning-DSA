#include<bits/stdc++.h>
using namespace std;

//this question can be done simillary to previous question just take the k instead of 2
//here we will try to optimise the time from O(n^3) to O(n^2) and rest logic is same.

//recursive appraoch
int solveRec(int ind, int op, vector<int> &prices, int k){
    if(ind == prices.size())
        return 0;

    if(op == 2*k)
        return 0;

    int profit = 0;
    if(op&1){
        int sell = prices[ind] + solveRec(ind+1, op+1, prices, k);
        int notSell = solveRec(ind+1, op, prices, k);
        profit = max(sell, notSell);
    }
    else{
        int buy = -prices[ind] + solveRec(ind+1, op+1, prices, k);
        int notBuy = solveRec(ind+1, op, prices, k);
        profit = max(buy, notBuy);
    }

    return profit;
}

int maxProfitRec(int k, vector<int>& prices) {
    return solveRec(0, 0, prices, k);
}

//using memoisation
int solveMemo(int ind, int op, vector<int> &prices, int k, vector<vector<int>> &dp){
    if(ind == prices.size())
        return 0;

    if(op == 2*k)
        return 0;

    if(dp[ind][op] != -1)
        return dp[ind][op];

    int profit = 0;
    if(op&1){
        int sell = prices[ind] + solveMemo(ind+1, op+1, prices, k, dp);
        int notSell = solveMemo(ind+1, op, prices, k, dp);
        profit = max(sell, notSell);
    }
    else{
        int buy = -prices[ind] + solveMemo(ind+1, op+1, prices, k, dp);
        int notBuy = solveMemo(ind+1, op, prices, k, dp);
        profit = max(buy, notBuy);
    }

    return dp[ind][op] = profit;
}

int maxProfitMemo(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));
    return solveMemo(0, 0, prices, k, dp);
}

//using tabulation
int solveTab(int k, vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int ind = n-1; ind >= 0; ind--){
        for(int op = 0; op < 2*k; op++){
            int profit = 0;
            if(op&1){
                int sell = prices[ind] + dp[ind+1][op+1];
                int notSell = dp[ind+1][op];
                profit = max(sell, notSell);
            }
            else{
                int buy = -prices[ind] + dp[ind+1][op+1];
                int notBuy = dp[ind+1][op];
                profit = max(buy, notBuy);
            }
            dp[ind][op] = profit;
        }
    }

    return dp[0][0];
}

int maxProfitTab(int k, vector<int>& prices) {
    return solveTab(k, prices);
}

//using space optimisation
int solveOpt(int k, vector<int>& prices){
    int n = prices.size();
    vector<int> curr(2*k+1, 0);
    vector<int> next(2*k+1, 0);

    for(int ind = n-1; ind >= 0; ind--){
        for(int op = 0; op < 2*k; op++){
            int profit = 0;
            if(op&1){
                int sell = prices[ind] + next[op+1];
                int notSell = next[op];
                profit = max(sell, notSell);
            }
            else{
                int buy = -prices[ind] + next[op+1];
                int notBuy = next[op];
                profit = max(buy, notBuy);
            }
            curr[op] = profit;
        }
        next = curr;
    }

    return next[0];
}

int maxProfitOpt(int k, vector<int>& prices) {
    return solveOpt(k, prices);
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