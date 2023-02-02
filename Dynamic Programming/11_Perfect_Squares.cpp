#include<bits/stdc++.h>
using namespace std;

//recursive way
int solveRec(int n){
    if(n == 0)
        return 0;

    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1+solveRec(n-i*i));
    }

    return ans;
}

int numSquareRec(int n){
    return solveRec(n);
}

//using memoisation
int solveMemo(int n, vector<int> &dp){
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int ans = n;
    for(int i = 1; i*i <= n; i++){
        ans = min(ans, 1+solveMemo(n-i*i, dp));
    }

    return dp[n] = ans;
}

int numSquareMemo(int n) {
    vector<int> dp(n+1, -1);
    return solveMemo(n, dp);
}

// using tabulation
int numSquareMemo(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j*j <= n; j++)
            if(i-j*j >= 0)
                dp[i] = min(dp[i], 1+dp[i-j*j]);

    return dp[n];
}

int main(){
    int n;
    cout<<"Enter the values  ";
    cin>>n;

    // using recursion
    cout<<"the least number of perfect square numbers that sum to n is "<<numSquareRec(n)<<endl;

    // using memoisation
    cout<<"the least number of perfect square numbers that sum to n is "<<numSquareMemo(n)<<endl;
 return 0;
}