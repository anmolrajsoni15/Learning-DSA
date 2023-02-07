#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(vector<int> &stsf, int ind, int time){
    if(ind >= stsf.size())
        return 0;

    int take = stsf[ind]*(time+1) + solveRec(stsf, ind+1, time+1);
    int notTake = solveRec(stsf, ind+1, time);

    return max(take, notTake);
}

int maxSatisfactionRec(vector<int> &stsf){
    sort(stsf.begin(), stsf.end());
    return solveRec(stsf, 0, 0);
}

//using memoisation
int solveMemo(vector<int> &stsf, int ind, int time, vector<vector<int>> &dp){
    if(ind >= stsf.size())
        return 0;

    if(dp[ind][time] != -1)
        return dp[ind][time];

    int take = stsf[ind]*(time+1) + solveMemo(stsf, ind+1, time+1, dp);
    int notTake = solveMemo(stsf, ind+1, time, dp);

    return dp[ind][time] = max(take, notTake);
}

int maxSatisfactionMemo(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solveMemo(satisfaction, 0, 0, dp);
}

//using tabulation
int maxSatisfactionTab(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind = n-1; ind>=0; ind--){
        for(int time = ind; time>=0; time--){
            int take = satisfaction[ind]*(time+1) + dp[ind+1][time+1];
            int notTake = dp[ind+1][time];
            dp[ind][time] = max(take, notTake);
        }
    }

    return dp[0][0];
}

// using space optimisation
int maxSatisfactionOpt(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int ind = n-1; ind>=0; ind--){
        for(int time = ind; time>=0; time--){
            int take = satisfaction[ind]*(time+1) + next[time+1];
            int notTake = next[time];
            curr[time] = max(take, notTake);
        }
        next = curr;
    }

    return next[0];
}

//further more space optimisation
int maxSatisfactionOpt2(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> next(n+1, 0);

    for(int ind = n-1; ind>=0; ind--){
        for(int time = 0; time<=ind; time++){
            int take = satisfaction[ind]*(time+1) + next[time+1];
            int notTake = next[time];
            next[time] = max(take, notTake);
        }
    }

    return next[0];
}

//ultra level time and space optimisation
int maxSatisfactionOptMax(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    int curSum = 0,sufSum = 0;
    for(int i = satisfaction.size()-1;i>=0;--i){
        if(sufSum + satisfaction[i] > 0){
            curSum += sufSum + satisfaction[i];
            sufSum += satisfaction[i];
        }
        else break;
    }
    return curSum;
}

int main(){
    int n;
    cout<<"Enter total dishes  ";
    cin>>n;

    vector<int> satisfaction(n);
    for(int i = 0; i<n; i++)
        cin>>satisfaction[i];

    //using recursion
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionRec(satisfaction)<<endl;

    //using memoisation
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionMemo(satisfaction)<<endl;

    //using tabulation
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionTab(satisfaction)<<endl;

    //using space optimisation
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionOpt(satisfaction)<<endl;

    //using further space optimisation
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionOpt2(satisfaction)<<endl;

    //using ultra space and time optimisation
    cout<<"Maximum like-time coefficient the chef can get is "<<maxSatisfactionOptMax(satisfaction)<<endl;
 return 0;
}