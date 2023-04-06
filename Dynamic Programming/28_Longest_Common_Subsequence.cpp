#include<bits/stdc++.h>
using namespace std;

//this question can also be used to find longest common palindromic subsequence

//recursive approach
int solveRec(string &a, string &b, int i, int j){
    if(i == a.length() || j == b.length())
        return 0;

    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveRec(a, b, i+1, j+1);
    else
        ans = max(solveRec(a, b, i+1, j), solveRec(a, b, i, j+1));

    return ans;
}

int LCSrec(string text1, string text2) {
    return solveRec(text1, text2, 0, 0);
}

//using memoisation
int solveMemo(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(i == a.length() || j == b.length())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveMemo(a, b, i+1, j+1, dp);
    else
        ans = max(solveMemo(a, b, i+1, j, dp), solveMemo(a, b, i, j+1, dp));

    return dp[i][j] = ans;
}

int LCSmemo(string text1, string text2) {
    vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length(), -1));
    return solveMemo(text1, text2, 0, 0, dp);
}

//using tabulation
int solveTab(string a, string b){
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + dp[i+1][j+1];
            else
                ans = max(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int LCStab(string text1, string text2) {
    return solveTab(text1, text2);
}

//using space optimisation
int solveOpt(string a, string b){
    int n = a.length(), m = b.length();
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j], curr[j+1]);
            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int LCSopt(string text1, string text2) {
    return solveOpt(text1, text2);
}

int main(){
    string text1, text2;
    cout<<"Enter the two strings:- \n";
    cin>>text1>>text2;
 return 0;
}