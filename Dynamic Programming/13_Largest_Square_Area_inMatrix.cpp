#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(vector<vector<int>> &m, int i, int j, int &maxi){
    if(i >= m.size() || j >= m[0].size())
        return 0;

    int right = solveRec(m, i, j+1, maxi);
    int diag = solveRec(m, i+1, j+1, maxi);
    int down = solveRec(m, i+1, j, maxi);

    if(m[i][j] == 1){
        int ans = 1 + min({right, diag, down});
        maxi = max(maxi, ans);
        return ans;
    }
    else    return 0;
}

int areaRec(int n, int m, vector<vector<int>> &matrix){
    int maxi = 0;
    solveRec(matrix, 0, 0, maxi);
    return maxi*maxi;
}

//using memoisation
int solveMemo(vector<vector<int>> &m, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= m.size() || j >= m[0].size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = solveMemo(m, i, j+1, maxi, dp);
    int diag = solveMemo(m, i+1, j+1, maxi, dp);
    int down = solveMemo(m, i+1, j, maxi, dp);

    int ans = 0;
    if(m[i][j] == 1){
        ans = 1 + min({right, diag, down});
        maxi = max(maxi, ans);
    }
        
    return dp[i][j] = ans;
}

int areaMemo(int n, int m, vector<vector<int>> &matrix){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = 0;
    solveMemo(matrix, 0, 0, maxi, dp);
    return maxi*maxi;
}

//using tabulation
int areaTab(int n, int m, vector<vector<int>> &matrix){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int maxi = 0;

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int right = dp[i][j+1];
            int diag = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(matrix[i][j] == 1){
                dp[i][j] = 1+min({right, diag, down});
                maxi = max(maxi, dp[i][j]);
            }
            else    dp[i][j] = 0;
        }
    }

    return maxi*maxi;
}

//using space optimisation
int areaOpt(int n, int m, vector<vector<int>> &matrix){
    vector<int> curr(m+1, 0);
    vector<int> next(m+1, 0);
    int maxi = 0;

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            int right = curr[j+1];
            int diag = next[j+1];
            int down = next[j];

            if(matrix[i][j] == 1){
                curr[j] = 1+min({right, diag, down});
                maxi = max(maxi, curr[j]);
            }
            else    curr[j] = 0;
        }
        next = curr;
    }

    return maxi*maxi;
}

int main(){
    int n, m;
    cout<<"Enter the row and column size:- ";
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout<<"Create the matrix:-\n";
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>matrix[i][j];

    cout<<"The area of largest square matrix is ";
 return 0;
}