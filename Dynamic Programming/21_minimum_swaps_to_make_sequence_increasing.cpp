#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solveRec(int index, vector<int>& nums1, vector<int>& nums2, bool swapped){
    if(index == nums1.size())
        return 0;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    int ans = INT_MAX;
    if(swapped)
        swap(prev1, prev2);

    //not swap
    if(nums1[index]>prev1 && nums2[index]>prev2)
        ans = solveRec(index+1, nums1, nums2, 0);

    // swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
        ans = min(ans, 1+solveRec(index+1, nums1, nums2, 1));

    return ans;
}

int minSwapRec(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    return solveRec(1, nums1, nums2, swapped);
}

// using memoisation
int solveMemo(int index, vector<int>& nums1, vector<int>& nums2, bool swapped, vector<vector<int>> &dp){
    if(index == nums1.size())
        return 0;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    int ans = INT_MAX;
    if(swapped)
        swap(prev1, prev2);

    if(dp[index][swapped] != -1)
        return dp[index][swapped];

    //not swap
    if(nums1[index]>prev1 && nums2[index]>prev2)
        ans = solveMemo(index+1, nums1, nums2, 0, dp);

    // swap
    if(nums1[index]>prev2 && nums2[index]>prev1)
        ans = min(ans, 1+solveMemo(index+1, nums1, nums2, 1, dp));

    return dp[index][swapped] = ans;
}

int minSwapMemo(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    bool swapped = 0;
    vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));
    return solveMemo(1, nums1, nums2, swapped, dp);
}

//using tabulation
int minSwapTab(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();

    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index = n-1; index>=1; index--){
        for(int swapped = 1; swapped>=0; swapped--){
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            int ans = INT_MAX;
            if(swapped)
                swap(prev1, prev2);

            //not swap
            if(nums1[index]>prev1 && nums2[index]>prev2)
                ans = dp[index+1][0];

            // swap
            if(nums1[index]>prev2 && nums2[index]>prev1)
                ans = min(ans, 1+dp[index+1][1]);

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

//using space optimisation
int minSwapTab(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int index = n-1; index>=1; index--){
        for(int swapped = 1; swapped>=0; swapped--){
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            int ans = INT_MAX;
            if(swapped)
                swap(prev1, prev2);

            //not swap
            if(nums1[index]>prev1 && nums2[index]>prev2)
                ans = next[0];

            // swap
            if(nums1[index]>prev2 && nums2[index]>prev1)
                ans = min(ans, 1+next[1]);

            curr[swapped] = ans;
        }
        next = curr;
    }

    return next[0];
}

int main(){
    int n;
    cout<<"Enter the size of the array:- ";
    cin>>n;

    vector<int> nums1(n), nums2(n);
    cout<<"Enter the values in nums1\n";
    for(int i = 0; i<n; i++)
        cin>>nums1[i];
    cout<<"Enter the values in nums2\n";
    for(int i = 0; i<n; i++)
        cin>>nums2[i];
 return 0;
}