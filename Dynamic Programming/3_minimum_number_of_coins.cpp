#include<bits/stdc++.h>
using namespace std;

//using recursion
int minCoinRec(vector<int> &coin, int t){
    if(t == 0)
        return 0;

    if(t < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0; i<coin.size(); i++){
        int ans = minCoinRec(coin, t-coin[i]); 
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    return mini;
}

int returnAns1(vector<int> &coin, int t){
    int ans = minCoinRec(coin, t);
    if(ans == INT_MAX)
        return -1;
    else    return ans;
}

//using memoization
int minCoinMemo(vector<int> &coin, int t, vector<int> &dp){
    if(t == 0)
        return 0;

    if(t < 0)
        return INT_MAX;

    if(dp[t] != -1)
        return dp[t];

    int mini = INT_MAX;
    for(int i = 0; i<coin.size(); i++){
        int ans = minCoinRec(coin, t-coin[i]); 
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    dp[t] = mini;

    return mini;
    
}

int returnAns2(vector<int> &coin, int t){
    vector<int> dp(t+1, -1);
    int ans = minCoinMemo(coin, t, dp);
    if(ans == INT_MAX)
        return -1;
    else    return ans;
}

//using tabulation
int minCoinTab(vector<int> &coin, int t){
    vector<int> dp(t+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i<=t; i++){
        for(int j = 0; j<coin.size(); j++){
            if(i-coin[j] >= 0 && dp[i-coin[j]] != INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-coin[j]]);
            }
        }
    }

    if(dp[t] == INT_MAX)
        return -1;
    else    return dp[t];
}

int main(){
    int n;
    cout<<"Enter the size of coin array:- ";
    cin>>n;

    vector<int> coin(n);
    cout<<"Enter the values for coin array:-\n";
    for(int i = 0; i<n; i++)
        cin>>coin[i];

    int cost;
    cout<<"Enter the target cost  ";
    cin>>cost;

    //recursive approach
    cout<<"Minimum number of coins to reach the target cost "<<returnAns1(coin, cost)<<endl;

    //using memoization
    cout<<"Minimum number of coins to reach the target cost "<<returnAns2(coin, cost)<<endl;

    //using tabulation
    cout<<"Minimum number of coins to reach the target cost "<<minCoinTab(coin, cost)<<endl;

 return 0;
}