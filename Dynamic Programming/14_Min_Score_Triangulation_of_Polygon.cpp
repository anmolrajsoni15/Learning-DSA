#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(vector<int> &v, int i, int j){
    if(i+1 == j)
        return 0;

    int ans = INT_MAX;
    for(int k = i+1; k<j; k++)
        ans = min(ans, (v[i]*v[j]*v[k])+(solveRec(v, i, k) + solveRec(v, k, j)));
    
    return ans;
}

int minScoreRec(vector<int> &values){
    int n = values.size();
    return solveRec(values, 0, n-1);
}

//using memoisation
int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    if(i+1 == j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k = i+1; k<j; k++)
        ans = min(ans, (v[i]*v[j]*v[k])+(solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp)));
    
    return dp[i][j] = ans;
}

int minScoreMemo(vector<int> &values){
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMemo(values, 0, n-1, dp);
}

//using tabulation
int minScoreTab(vector<int> &v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-3; i>=0; i--){
        for(int j = i+2; j<n; j++){
            int ans = INT_MAX;
            for(int k = i+1; k<j; k++)
                ans = min(ans, (v[i]*v[j]*v[k])+(dp[i][k] + dp[k][j]));
            dp[i][j] = ans;
        }
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cout<<"Size of the polygon:- ";
    cin>>n;
    vector<int> values(n);
    cout<<"Enter the corresponding values of each edge:-\n";
    for(int i = 0; i<n; i++)
        cin>>values[i];

    //recursive way
    cout<<"The minimum score of triangulation of polygon is "<<minScoreRec(values)<<endl;

    //using memoisation
    cout<<"The minimum score of triangulation of polygon is "<<minScoreMemo(values)<<endl;

    //using tabulation
    cout<<"The minimum score of triangulation of polygon is "<<minScoreTab(values)<<endl;
 return 0;
}