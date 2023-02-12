#include<bits/stdc++.h>
using namespace std;

//recursive way
int solveRec(int n){
    if( n <= 1 )
        return 1;

    int ans = 0;
    for(int i = 1; i<=n; i++)
        ans += solveRec(i-1)*solveRec(n-i);

    return ans;
}

int numTreesRec(int n){
    return solveRec(n);
}

//using memoisation
int solveMemo(int n, vector<int> &dp){
    if( n <= 1 )
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for(int i = 1; i<=n; i++)
        ans += solveMemo(i-1, dp)*solveMemo(n-i, dp);

    return dp[n] = ans;
}

int numTreesMemo(int n){
    vector<int> dp(n+1, -1);
    return solveMemo(n, dp);
}

//using tabulation
int numTreesTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n; i++)
        for(int j = 1; j<=i; j++)
            dp[i] += dp[j-1]*dp[i-j];

    return dp[n];
}

int main(){
    int n;
    cout<<"Number of elements in the BST:- ";
    cin>>n;
 return 0;
}