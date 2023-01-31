#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solve1(vector<int> &arr, int n){
    if(n < 0)   return 0;
    if(n == 0)  return arr[0];

    int take = solve1(arr, n-2) + arr[n];
    int notTake = solve1(arr, n-1);

    return max(take, notTake);
}

int maxSumRec(vector<int> &arr){
    int n = arr.size();
    int ans = solve1(arr, n-1);
    return ans;
}

//using memoisation
int solve2(int n, vector<int> &arr, vector<int> &dp){
    if(n < 0)   return 0;
    if(n == 0)  return arr[0];
    if(dp[n] != -1)    return dp[n];

    int take = solve2(n-2, arr, dp) + arr[n];
    int notTake = solve2(n-1, arr, dp);

    return dp[n] = max(take, notTake);
}

int maxSumMemo(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n+1, -1);

    int ans = solve2(n-1, arr, dp);
    return ans;
}

//using tabulation
int maxSumTab(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n, 0);

    dp[0] = arr[0];

    for(int i = 1; i<n; i++){
        int take = arr[i];
        if(i-2 >= 0){
            take += dp[i-2];
        }
        int notTake = dp[i-1];
        dp[i] = max(take, notTake);
    }

    return dp[n-1];
}

//using space optimisation
int maxSumOpt(vector<int> &arr){
    int n = arr.size();
    int prev2 = 0;
    int prev1 = arr[0];

    for(int i = 1; i<n; i++){
        int take = prev2 + arr[i];
        int notTake = prev1;
        int ans = max(take, notTake);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    int n;
    cout<<"Enter the size of array:- ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the values for array:-\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    //recursively
    cout<<"Maximum Sum of Non Adjacent Element is "<<maxSumRec(arr)<<endl;

    //using memoisation
    cout<<"Maximum Sum of Non Adjacent Element is "<<maxSumMemo(arr)<<endl;

    //using tabulation
    cout<<"Maximum Sum of Non Adjacent Element is "<<maxSumTab(arr)<<endl;

    //using space optimisation
    cout<<"Maximum Sum of Non Adjacent Element is "<<maxSumOpt(arr)<<endl;
 return 0;
}