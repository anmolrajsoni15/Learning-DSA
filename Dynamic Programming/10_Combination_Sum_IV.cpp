#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(vector<int> &nums, int t){
    if(t == 0)
        return 1;

    if(t < 0)
        return 0;

    int ans = 0;
    for(int i = 0; i<nums.size(); i++){
        ans += solveRec(nums, t-nums[i]);
    }

    return ans;
}

int combSumRec(vector<int> &nums, int target){
    return solveRec(nums, target);
}

//using memoisation
int solveMemo(vector<int> &nums, int t, vector<int> &dp){
    if(t == 0)
        return 1;

    if(t < 0)
        return 0;

    if(dp[t] != -1)
        return dp[t];

    int ans = 0;
    for(int i = 0; i<nums.size(); i++){
        ans += solveMemo(nums, t-nums[i], dp);
    }

    return dp[t] = ans;
}

int combSumMemo(vector<int> &nums, int target){
    vector<int> dp(target+1, -1);
    return solveMemo(nums, target, dp);
}

//using tabulation
int combSumTab(vector<int> &nums, int target){
    vector<int> dp(target+1, 0);
    dp[0] = 0;

    for(int i = 1; i<= target; i++){
        for(int j = 0; j<nums.size(); j++){
            if(i-nums[j] >= 0)
                dp[i] += dp[i-nums[j]];
        }
    }

    return dp[target];
}

int main(){
    int n;
    cout<<"Enter the size of array :-  ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter values in the nums array\n";
    for(int i = 0; i<n; i++)
        cin>>nums[i];

    int target;
    cout<<"Enter the target value :- ";
    cin>>target;

    //using recursion
    cout<<"Number of ways to get the target is "<<combSumRec(nums, target)<<endl;

    //using memoisation
    cout<<"Number of ways to get the target is "<<combSumMemo(nums, target)<<endl;

    //using tabulation
    cout<<"Number of ways to get the target is "<<combSumTab(nums, target)<<endl;
 return 0;
}