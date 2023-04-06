#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(string &a, string &b, int i, int j){
    if(i == a.length())
        return b.length()-j;

    if(j == b.length())
        return a.length()-i;

    int ans = 0;
    if(a[i] == b[j])
        return solveRec(a, b, i+1, j+1);
    else{
        int insert = 1 + solveRec(a, b, i, j+1);
        int Delete = 1 + solveRec(a, b, i+1, j);
        int replace = 1 + solveRec(a, b, i+1, j+1);
        ans = min({insert, Delete, replace});
    }

    return ans;
}

int minDistanceRec(string word1, string word2) {
    return solveRec(word1, word2, 0, 0);
}

//using memoisation
int solveMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(i == a.length())
        return b.length()-j;

    if(j == b.length())
        return a.length()-i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])
        return solveMemo(a, b, i+1, j+1, dp);
    else{
        int insert = 1 + solveMemo(a, b, i, j+1, dp);
        int Delete = 1 + solveMemo(a, b, i+1, j, dp);
        int replace = 1 + solveMemo(a, b, i+1, j+1, dp);
        ans = min({insert, Delete, replace});
    }

    return dp[i][j] = ans;
}

int minDistanceMemo(string word1, string word2) {
    vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, -1));
    return solveMemo(word1, word2, 0, 0, dp);
}

//using tabulation
int solveTab(string &a, string &b){
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j = 0; j<m; j++)
        dp[n][j] = m-j;

    for(int i = 0; i<n; i++)
        dp[i][m] = n-i;

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = dp[i+1][j+1];
            else{
                int insert = 1 + dp[i][j+1];
                int Delete = 1 + dp[i+1][j];
                int replace = 1 + dp[i+1][j+1];
                ans = min({insert, Delete, replace});
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int minDistanceTab(string word1, string word2) {
    return solveTab(word1, word2);
}

//using space optimisation
int solveOpt(string &a, string &b){
    int n = a.length(), m = b.length();
    if(n == 0)
        return m;
    if(m == 0)
        return n;
        
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int j = 0; j<m; j++)
        next[j] = m-j;

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            curr[m] = n-i;

            int ans = 0;
            if(a[i] == b[j])
                ans = next[j+1];
            else{
                int insert = 1 + curr[j+1];
                int Delete = 1 + next[j];
                int replace = 1 + next[j+1];
                ans = min({insert, Delete, replace});
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int minDistanceOpt(string word1, string word2) {
    return solveOpt(word1, word2);
}

int main(){
    string word1, word2;
    cout<<"Enter the two words:- ";
    cin>>word1>>word2;
 return 0;
}