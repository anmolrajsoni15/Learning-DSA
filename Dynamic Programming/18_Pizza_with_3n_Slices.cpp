#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int ind, int end, vector<int> &score, int len){
    if(len == 0 || ind > end)
        return 0;

    int take = score[ind] + solveRec(ind+2, end, score, len-1);
    int notTake = solveRec(ind+1, end, score, len);

    return max(take, notTake);
}

int maxSizeSlicesRec(vector<int> &score){
    int n = score.size();
    int case1 = solveRec(0, n-2, score, n/3);
    int case2 = solveRec(1, n-1, score, n/3);

    return max(case1, case2);
}

//using memoisation
int solveMemo(int ind, int end, vector<int> &score, int len, vector<vector<int>> &dp){
    if(len == 0 || ind > end)
        return 0;

    if(dp[ind][len] != -1)
        return dp[ind][len];

    int take = score[ind] + solveMemo(ind+2, end, score, len-1, dp);
    int notTake = solveMemo(ind+1, end, score, len, dp);

    return dp[ind][len] = max(take, notTake);
}

int maxSizeSlicesMemo(vector<int>& slices) {
    int n = slices.size();
    vector<vector<int>> dp1(n, vector<int>(n, -1));
    int case1 = solveMemo(0, n-2, slices, n/3, dp1);
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    int case2 = solveMemo(1, n-1, slices, n/3, dp2);

    return max(case1, case2);
}

//using tabulation
int maxSizeSlicesTab(vector<int>& slices) {
    int n = slices.size();
    vector<vector<int>> dp1(n+2, vector<int>(n/3+1, 0));
    vector<vector<int>> dp2(n+2, vector<int>(n/3+1, 0));

    // case 1
    for(int ind = n-2; ind>=0; ind--){
        for(int len = 1; len<=n/3; len++){
            int take = slices[ind] + dp1[ind+2][len-1];
            int notTake = dp1[ind+1][len];

            dp1[ind][len] = max(take, notTake);
        }
    }
    int case1 = dp1[0][n/3];
    
    // case 2
    for(int ind = n-1; ind>=1; ind--){
        for(int len = 1; len<=n/3; len++){
            int take = slices[ind] + dp2[ind+2][len-1];
            int notTake = dp2[ind+1][len];

            dp2[ind][len] = max(take, notTake);
        }
    }
    int case2 = dp2[1][n/3];

    return max(case1, case2);
}

//using space optimisation
int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();

    vector<int> prev1(n+1, 0);
    vector<int> curr1(n+1, 0);
    vector<int> next1(n+1, 0);

    vector<int> prev2(n+1, 0);
    vector<int> curr2(n+1, 0);
    vector<int> next2(n+1, 0);

    // case 1
    for(int ind = n-2; ind>=0; ind--){
        for(int len = 1; len<=n/3; len++){
            int take = slices[ind] + next1[len-1];
            int notTake = curr1[len];

            prev1[len] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[n/3];
    
    // case 2
    for(int ind = n-1; ind>=1; ind--){
        for(int len = 1; len<=n/3; len++){
            int take = slices[ind] + next2[len-1];
            int notTake = curr2[len];

            prev2[len] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[n/3];

    return max(case1, case2);
}


int main(){
    int n;
    cout<<"Number of scores in pizza:- ";
    cin>>n;

    vector<int> score(n);
    for(int i = 0; i<n; i++)
        cin>>score[i];
 return 0;
}