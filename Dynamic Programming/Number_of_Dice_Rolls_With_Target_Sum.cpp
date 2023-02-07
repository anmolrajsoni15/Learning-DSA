#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

//recursive approach
int solveRec(int dice, int face, int target){
    if(target < 0)
        return 0;

    if(dice == 0 && target != 0)
        return 0;

    if(target == 0 && dice != 0)
        return 0;

    if(target == 0 && dice == 0)
        return 1;

    int ans = 0;
    for(int i = 1; i<=face; i++){
        ans = (ans + solveRec(dice-1, face, target-i))%mod;
    }

    return ans;
}

int numRollsToTargetRec(int n, int k, int target) {
    return solveRec(n, k, target);
}

//using memoisation
int solveMemo(int dice, int face, int target, vector<vector<int>> &dp){
    if(target < 0)
        return 0;

    if(dice == 0 && target != 0)
        return 0;

    if(target == 0 && dice != 0)
        return 0;

    if(target == 0 && dice == 0)
        return 1;

    if(dp[dice][target] != -1)
        return dp[dice][target];

    int ans = 0;
    for(int i = 1; i<=face; i++){
        ans = (ans + solveMemo(dice-1, face, target-i, dp))%mod;
    }

    return dp[dice][target] = ans;
}

int numRollsToTargetMemo(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
    return solveMemo(n, k, target, dp);
}

//using tabulation
int numRollsToTargetTab(int n, int k, int target) {
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;

    for(int dice = 1; dice <= n; dice++){
        for(int tar = 1; tar <= target; tar++){
            int ans = 0;
            for(int face = 1; face <= k; face++){
                if(tar-face >= 0)
                    ans = (ans + dp[dice-1][tar-face])%mod;
            }
            dp[dice][tar] = ans;
        }
    }

    return dp[n][target];
}

//using space optimisation
int numRollsToTargetOpt(int n, int k, int target) {
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    prev[0] = 1;

    for(int dice = 1; dice <= n; dice++){
        for(int tar = 1; tar <= target; tar++){
            int ans = 0;
            for(int face = 1; face <= k; face++){
                if(tar-face >= 0)
                    ans = (ans + prev[tar-face])%mod;
            }
            curr[tar] = ans;
        }
        prev = curr;
    }

    return prev[target];
}

int main(){
    int n, k, target;
    cout<<"Enter the number of dices, number of faces in each dice and the target sum respectively:-\n";
    cin>>n>>k>>target;

    //using recursion
    cout<<"Total no. of ways to roll a dice to get the target sum is "<<numRollsToTargetRec(n, k, target)<<endl;

    //using memoisation
    cout<<"Total no. of ways to roll a dice to get the target sum is "<<numRollsToTargetMemo(n, k, target)<<endl;

    //using tabulation
    cout<<"Total no. of ways to roll a dice to get the target sum is "<<numRollsToTargetTab(n, k, target)<<endl;

    //using space optimisation
    cout<<"Total no. of ways to roll a dice to get the target sum is "<<numRollsToTargetOpt(n, k, target)<<endl;
 return 0;
}