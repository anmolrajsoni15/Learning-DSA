#include<bits/stdc++.h>
using namespace std;

// recursive approach
int solveRec(vector<int> &obt, int lane, int pos){
    if(pos == obt.size()-1)
        return 0;

    if(obt[pos+1] != lane)
        return solveRec(obt, lane, pos+1);
    else{
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++)
            if(lane != i && obt[pos] != i)
                ans = min(ans, 1+solveRec(obt, i, pos));
        return ans;
    }
}

int minSideJumpRec(vector<int> &obstacles){
    return solveRec(obstacles, 2, 0);
}

//using memoisation
int solveMemo(vector<int> &obt, int lane, int pos, vector<vector<int>> &dp){
    if(pos == obt.size()-1)
        return 0;

    if(dp[lane][pos] != -1)
        return dp[lane][pos];

    if(obt[pos+1] != lane)
        return dp[lane][pos] = solveMemo(obt, lane, pos+1, dp);
    else{
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++)
            if(lane != i && obt[pos] != i)
                ans = min(ans, 1+solveMemo(obt, i, pos, dp));
        return dp[lane][pos] = ans;
    }
}

int minSideJumpMemo(vector<int> &obstacles){
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, -1));
    return solveMemo(obstacles, 2, 0, dp);
}

//using tabulation
int minSideJumpTab(vector<int> &obstacles){
    int n = obstacles.size()-1;
    vector<vector<int>> dp(4, vector<int>(n+1, INT_MAX));

    for(int i = 0; i<4; i++)
        dp[i][n] = 0;

    for(int pos = n-1; pos>=0; pos--){
        for(int lane = 1; lane<=3; lane++){
            if(obstacles[pos+1] != lane)
                dp[lane][pos] = dp[lane][pos+1];
            else{
                int ans = INT_MAX;
                for(int i = 1; i<=3; i++)
                    if(lane != i && obstacles[pos] != i)
                        ans = min(ans, 1+dp[i][pos+1]);
                dp[lane][pos] = ans;
            }
        }
    }

    return min({dp[2][0], 1+dp[1][0], 1+dp[3][0]});
}

//using space optimisation
int minSideJumpOpt(vector<int> &obstacles){
    int n = obstacles.size()-1;
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    for(int i = 0; i<4; i++)
        next[i] = 0;

    for(int pos = n-1; pos>=0; pos--){
        for(int lane = 1; lane<=3; lane++){
            if(obstacles[pos+1] != lane)
                curr[lane] = next[lane];
            else{
                int ans = INT_MAX;
                for(int i = 1; i<=3; i++)
                    if(lane != i && obstacles[pos] != i)
                        ans = min(ans, 1+next[i]);
                curr[lane] = ans;
            }
        }
        next = curr;
    }
    return min({next[2], 1+next[1], 1+next[3]});
}

int main(){
    int n;
    cout<<"Enter the length of the road  ";
    cin>>n;
    vector<int> obstacles(n);
    for(int i = 0; i<n; i++)
        cin>>obstacles[i];

    //using recursion
    cout<<"Minimum number of sideway jumps required to reach the destination is "<<minSideJumpRec(obstacles)<<endl;

    //using memoisation
    cout<<"Minimum number of sideway jumps required to reach the destination is "<<minSideJumpMemo(obstacles)<<endl;

    //using tabulation
    cout<<"Minimum number of sideway jumps required to reach the destination is "<<minSideJumpTab(obstacles)<<endl;

    //using space optimisation
    cout<<"Minimum number of sideway jumps required to reach the destination is "<<minSideJumpOpt(obstacles)<<endl;
 return 0;
}