#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int s, int e){
    if(s >= e)
        return 0;

    int mini = INT_MAX;
    for(int i = s; i <= e; i++){
        mini = min(mini, i+max(solveRec(s, i-1), solveRec(i+1, e)));
    }

    return mini;
}

int getMoneyAmountRec(int n) {
    return solveRec(1, n);
}

//using memoisation
int solveMemo(int s, int e, vector<vector<int>> &dp){
    if(s >= e)
        return 0;

    if(dp[s][e] != -1)
        return dp[s][e];

    int mini = INT_MAX;
    for(int i = s; i <= e; i++){
        mini = min(mini, i+max(solveMemo(s, i-1, dp), solveMemo(i+1, e, dp)));
    }

    return dp[s][e] = mini;
}

int getMoneyAmountMemo(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMemo(1, n, dp);
}

//using tabulation
int getMoneyAmountTab(int n){
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int start = n; start >= 1; start--){
        for(int end = start; end <= n; end++){
            if(start == end)
                continue;
            else{
                int mini = INT_MAX;
                for(int i = start; i <= end; i++){
                    mini = min(mini, i+max(dp[start][i-1], dp[i+1][end]));
                }
                dp[start][end] = mini;
            }
        }
    }

    return dp[1][n];
}

int main(){
    int n;
    cout<<"Enter the range of the number  ";
    cin>>n;

    //using recursion
    cout<<"The minimum amount of money you need to guarantee a win regardless of what number other pick is "<<getMoneyAmountRec(n);

    //using memoisation
    cout<<"The minimum amount of money you need to guarantee a win regardless of what number other pick is "<<getMoneyAmountMemo(n);

    //using tabulation
    cout<<"The minimum amount of money you need to guarantee a win regardless of what number other pick is "<<getMoneyAmountTab(n);
 return 0;
}