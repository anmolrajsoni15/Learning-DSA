#include<bits/stdc++.h>
using namespace std;

//recursive way
bool solveRec(int ind, vector<int> &nums, int n, int tar){
    if(ind >= n)
        return false;

    if(tar < 0)
        return false;

    if(tar == 0)
        return true;

    bool take = solveRec(ind+1, nums, n, tar-nums[ind]);
    bool notTake = solveRec(ind+1, nums, n, tar);

    return take|notTake;
}

bool canPartitionRec(vector<int> &nums){
    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total & 1)
        return false;

    int target = total/2;
    return solveRec(0, nums, nums.size(), target);
}

//using memoisation
bool solveMemo(int ind, vector<int> &nums, int n, int tar, vector<vector<int>> &dp){
    if(ind >= n)
        return false;

    if(tar < 0)
        return false;

    if(tar == 0)
        return true;

    if(dp[ind][tar] != -1)
        return dp[ind][tar];

    bool take = solveMemo(ind+1, nums, n, tar-nums[ind], dp);
    bool notTake = solveMemo(ind+1, nums, n, tar, dp);

    return dp[ind][tar] = take|notTake;
}

bool canPartitionMemo(vector<int> &nums){
    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total & 1)
        return false;

    int target = total/2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
    return solveMemo(0, nums, nums.size(), target, dp);
}

//using memoisation
bool solveMemo(int ind, vector<int> &nums, int n, int tar, vector<vector<int>> &dp){
    if(ind >= n)
        return false;

    if(tar < 0)
        return false;

    if(tar == 0)
        return true;

    if(dp[ind][tar] != -1)
        return dp[ind][tar];

    bool take = solveMemo(ind+1, nums, n, tar-nums[ind], dp);
    bool notTake = solveMemo(ind+1, nums, n, tar, dp);

    return dp[ind][tar] = take|notTake;
}

bool canPartitionMemo(vector<int> &nums){
    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total & 1)
        return false;

    int target = total/2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));
    return solveMemo(0, nums, nums.size(), target, dp);
}

//using tabulation
bool canPartitionTab(vector<int> &nums){
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    if(total & 1)
        return false;

    int target = total/2;
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;

    for(int ind = n-1; ind >= 0; ind--){
        for(int tar = 1; tar <= target; tar++){
            bool take = 0;
            if(tar-nums[ind] >= 0)
                take = dp[ind+1][tar-nums[ind]];
            bool notTake = dp[ind+1][tar];
            dp[ind][tar] = take|notTake;
        }
    }

    return dp[0][target];
}

//using space optimisation
bool canPartitionOpt(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for(int num : nums)
        total += num;

    if(total & 1)
        return false;

    int target = total/2;
    vector<bool> curr(target+1, 0);
    vector<bool> next(target+1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int ind = n-1; ind >= 0; ind--){
        for(int tar = 1; tar <= target; tar++){
            bool take = 0;
            if(tar-nums[ind] >= 0)
                take = next[tar-nums[ind]];
            bool notTake = next[tar];
            curr[tar] = take|notTake;
        }
        next = curr;
    }

    return next[target];
}

int main(){
    int n;
    cout<<"Enter the size of the array:- ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the array elements\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    
 return 0;
}