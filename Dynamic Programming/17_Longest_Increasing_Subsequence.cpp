#include<bits/stdc++.h>
using namespace std;

//using recursion
int solveRec(int n, vector<int> &a, int prev, int curr){
    if(curr == n)
        return 0;

    int take = 0;
    if(prev == -1 || a[curr]>a[prev])
        take = 1+solveRec(n, a, curr, curr+1);
    int notTake = solveRec(n, a, prev, curr+1);

    return max(take, notTake);
}

int LIS_Rec(vector<int> &a, int n){
    return solveRec(n, a, -1, 0);
}

//using memoisation
int solveMemo(int n, vector<int> &a, int curr, int prev, vector<vector<int>> &dp){
    if(curr == n)
        return 0;

    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];

    int take = 0;
    if(prev == -1 || a[curr]>a[prev])
        take = 1+solveMemo(n, a, curr+1, curr, dp);
    int notTake = solveMemo(n, a, curr+1, prev, dp);

    return dp[curr][prev+1] = max(take, notTake);
}

int LIS_Memo(vector<int> &a, int n){
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solveMemo(n, a, 0, -1, dp);
}

//using tabulation
int LIS_Tab(vector<int> &a, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int take = 0;
            if(prev == -1 || (a[curr]>a[prev] && prev != -1))
                take = 1+dp[curr+1][curr+1];
            int notTake = dp[curr+1][prev+1];

            dp[curr][prev+1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

//using space optimisation
int LIS_Opt(vector<int> &a, int n){
    vector<int> currRow(n+1, 0);
    vector<int> next(n+1, 0);
    
    for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int take = 0;
            if(prev == -1 || (a[curr]>a[prev] && prev != -1))
                take = 1+next[curr+1];
            int notTake = next[prev+1];

            currRow[prev+1] = max(take, notTake);
        }
        next = currRow;
    }

    return next[0];
}

//dp with binary search
//time complexity:- O(nlogn)
//space complexity:- O(n)
int LIS_Optimal(vector<int> &a, int n){
    if(n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for(int i = 1; i<n; i++){
        if(a[i]>ans.back())
            ans.push_back(a[i]);
        else{
            int index = lower_bound(ans.begin(), ans.end(), a[i])-ans.begin();
            ans[index] = a[i];
        }
    }

    return ans.size();
}

int main(){
    int n;
    cout<<"Enter size of array  ";
    cin>>n;

    cout<<"Enter the elements:-\n";
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    //using recursion
    cout<<"The length longest increasing subsequence of given array is "<<LIS_Rec(arr, n)<<endl;

    //using memoisation
    cout<<"The length longest increasing subsequence of given array is "<<LIS_Memo(arr, n)<<endl;

    //using tabulation
    cout<<"The length longest increasing subsequence of given array is "<<LIS_Tab(arr, n)<<endl;

    //using space optimisation
    cout<<"The length longest increasing subsequence of given array is "<<LIS_Opt(arr, n)<<endl;

    //using time and space optimisation
    cout<<"The length longest increasing subsequence of given array is "<<LIS_Optimal(arr, n)<<endl;
 return 0;
}