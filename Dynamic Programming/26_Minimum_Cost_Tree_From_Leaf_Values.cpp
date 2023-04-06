#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(vector<int>& arr, int left, int right, map<pair<int, int>, int> &maxi){
    if(left == right)
        return 0;

    int ans = INT_MAX;
    for(int i = left; i < right; i++){
        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solveRec(arr, left, i, maxi) + solveRec(arr, i+1, right, maxi));
    }

    return ans;
}

int mctFromLeafValuesRec(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;

    for(int i = 0; i<arr.size(); i++){
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++)
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }

    return solveRec(arr, 0, n-1, maxi);
}

//using memoisation
int solveMemo(vector<int>& arr, int left, int right, map<pair<int, int>, int> &maxi, vector<vector<int>> &dp){
    if(left == right)
        return 0;

    if(dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;
    for(int i = left; i < right; i++){
        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + solveMemo(arr, left, i, maxi, dp) + solveMemo(arr, i+1, right, maxi, dp));
    }

    return dp[left][right] = ans;
}

int mctFromLeafValuesMemo(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    for(int i = 0; i<arr.size(); i++){
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++)
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }

    return solveMemo(arr, 0, n-1, maxi, dp);
}

//using tabulation
int solveTab(vector<int> &arr, map<pair<int, int>, int> &maxi, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int left = n-1; left >= 0; left--){
        for(int right = left+1; right <= n-1; right++){
            int ans = 1e9;
            for(int i = left; i < right; i++){
                ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
            }
            dp[left][right] = ans;
        }
    }

    return dp[0][n-1];
}

int mctFromLeafValuesTab(vector<int>& arr) {
    int n = arr.size();
    map<pair<int, int>, int> maxi;

    for(int i = 0; i<arr.size(); i++){
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j<arr.size(); j++)
            maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }

    return solveTab(arr, maxi, n);
}

int main(){
    int n;
    cout<<"Size of array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array elements\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

 return 0;
}