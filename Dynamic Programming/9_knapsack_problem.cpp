#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int index, vector<int> &weight, vector<int> &value, int maxW){
    if(index == 0){
        if(weight[index] <= maxW)
            return value[0];
        else    return 0;
    }

    int take = 0;
    if(weight[index] <= maxW)
        take = value[index] + solveRec(index-1, weight, value, maxW-weight[index]);

    int notTake = solveRec(index-1, weight, value, maxW);

    return max(take, notTake);
}

int knapsackRec(int n, vector<int> &weight, vector<int> &value, int maxW){
    return solveRec(n-1, weight, value, maxW);
}

// using memoisation
int solveMemo(int index, vector<int> &weight, vector<int> &value, int maxW, vector<vector<int>> &dp){
    if(index == 0){
        if(weight[index] <= maxW)
            return value[0];
        else    return 0;
    }

    if(dp[index][maxW] != -1)
        return dp[index][maxW];

    int take = 0;
    if(weight[index] <= maxW)
        take = value[index] + solveMemo(index-1, weight, value, maxW-weight[index], dp);

    int notTake = solveMemo(index-1, weight, value, maxW, dp);

    return dp[index][maxW] = max(take, notTake);
}

int knapsackMemo(int n, vector<int> &weight, vector<int> &value, int maxW){
    vector<vector<int>> dp(n, vector<int>(maxW+1, -1));
    return solveMemo(n-1, weight, value, maxW, dp);
}

//using tabulation
int knapsackTab(int n, vector<int> &weight, vector<int> &value, int maxW){
    vector<vector<int>> dp(n, vector<int>(maxW+1, 0));

    for(int w = weight[0]; w<=maxW; w++){
        if(weight[0] <= maxW)
            dp[0][w] = value[0];
        else    dp[0][w] = 0;
    }

    for(int ind = 1; ind<n; ind++){
        for(int w = 0; w <= maxW; w++){
            int take = 0;
            if(weight[ind] <= w)
                take = value[ind] + dp[ind-1][w-weight[ind]];
            int notTake = dp[ind-1][w];

            dp[ind][w] = max(take, notTake);
        }
    }

    return dp[n-1][maxW];
}

//using space optimisation
int knapsackOpt(int n, vector<int> &weight, vector<int> &value, int maxW){
    vector<int> prev(maxW+1, 0);
    vector<int> curr(maxW+1, 0);

    for(int w = weight[0]; w<=maxW; w++){
        if(weight[0] <= maxW)
            prev[w] = value[0];
        else    prev[w] = 0;
    }

    for(int ind = 1; ind<n; ind++){
        for(int w = 0; w <= maxW; w++){
            int take = 0;
            if(weight[ind] <= w)
                take = value[ind] + prev[w-weight[ind]];
            int notTake = prev[w];

            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[maxW];
}

int main(){
    int n;
    cout<<"Enter the total size:- ";
    cin>>n;

    vector<int> weight(n), value(n);
    cout<<"Weight array:- ";
    for(int i = 0; i<n; i++)
        cin>>weight[i];

    cout<<"Value array:- ";
    for(int i = 0; i<n; i++)
        cin>>value[i];

    int maxWeight;
    cout<<"Maximum weight capacity of the bag:- ";
    cin>>maxWeight;

    //using recursion
    cout<<"The max value is:- "<<knapsackRec(n, weight, value, maxWeight)<<endl;

    //using memoisation
    cout<<"The max value is:- "<<knapsackMemo(n, weight, value, maxWeight)<<endl;

    //using tabulation
    cout<<"The max value is:- "<<knapsackTab(n, weight, value, maxWeight)<<endl;

    //using space optimisation
    cout<<"The max value is:- "<<knapsackOpt(n, weight, value, maxWeight)<<endl;
 return 0;
}