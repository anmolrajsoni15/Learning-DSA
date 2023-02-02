#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int n, vector<int> &days, vector<int> &costs, int ind){
    if(ind >= n)
        return 0;

    //1-day pass
    int oneDay = costs[0] + solveRec(n, days, costs, ind+1);

    int i;
    //7-day pass
    for(i = ind; i<n && days[i]<days[ind]+7; i++);
    int sevenDays = costs[1] + solveRec(n, days, costs, i);

    //30-days pass
    for(i = ind; i<n && days[i]<days[ind]+30; i++);
    int thirtyDays = costs[2] + solveRec(n, days, costs, i);

    return min({oneDay, sevenDays, thirtyDays});

}

int minCostRec(int n, vector<int> &days, vector<int> &costs){
    return solveRec(n, costs, days, 0);
}

// using memoisation
int solveMemo(int n, vector<int> &days, vector<int> &costs, int ind, vector<int> &dp){
    if(ind >= n)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    //1-day pass
    int oneDay = costs[0] + solveMemo(n, days, costs, ind+1, dp);

    int i;
    //7-day pass
    for(i = ind; i<n && days[i]<days[ind]+7; i++);
    int sevenDays = costs[1] + solveMemo(n, days, costs, i, dp);

    //30-days pass
    for(i = ind; i<n && days[i]<days[ind]+30; i++);
    int thirtyDays = costs[2] + solveMemo(n, days, costs, i, dp);

    return dp[ind] = min({oneDay, sevenDays, thirtyDays});
}

int minCostMemo(int n, vector<int> &days, vector<int> &costs){
    vector<int> dp(n+1, -1);
    return solveMemo(n, days, costs, 0, dp);
}

//using tabulation
int minCostTab(int n, vector<int> &days, vector<int> &costs){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k = n-1; k>=0; k--){
        //1-day pass
        int oneDay = costs[0] + dp[k+1];

        int i;
        //7-day pass
        for(i = k; i<n && days[i]<days[k]+7; i++);
        int sevenDays = costs[1] + dp[i];

        //30-days pass
        for(i = k; i<n && days[i]<days[k]+30; i++);
        int thirtyDays = costs[2] + dp[i];

        dp[k] = min({oneDay, sevenDays, thirtyDays});
    }

    return dp[0];
}

//using space optimisation
int minCostOpt(int n, vector<int> &days, vector<int> &costs){
    int ans = 0;

    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for(int day : days){
        //remove extra days
        while(!week.empty() && week.front().first + 7 <= day)
            week.pop();
        while(!month.empty() && month.front().first + 30 <= day)
            month.pop();

        //add the current day
        week.push({day, ans+costs[1]});
        month.push({day, ans+costs[2]});

        ans = min({costs[0]+ans, week.front().second, month.front().second});
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter number of days for trip:- ";
    cin>>n;

    vector<int> days(n), cost(3);
    cout<<"Enter the days for trip\n";
    for(int i = 0; i<n; i++)
        cin>>days[i];

    cout<<"Enter the cost for 1-day, 7-day, 30-day pass:-  ";
    for(int i = 0; i<3; i++)
        cin>>cost[i];

    //using recursion
    cout<<"The minimum cost of the trip will be"<<minCostRec(n, days, cost)<<endl;

    //using memoisation
    cout<<"The minimum cost of the trip will be"<<minCostMemo(n, days, cost)<<endl;

    //using tabulation
    cout<<"The minimum cost of the trip will be"<<minCostTab(n, days, cost)<<endl;

    //using space optimisation
    cout<<"The minimum cost of the trip will be"<<minCostOpt(n, days, cost)<<endl;
 return 0;
}