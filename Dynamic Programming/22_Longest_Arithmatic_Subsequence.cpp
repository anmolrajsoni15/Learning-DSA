#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2)
        return n;

    int ans = 0;
    unordered_map<int, int> dp[N];    //we are creating this to count the number of elements in the subsequence at ith index with given comman difference

    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            int diff = nums[i]-nums[j]+505;
            int cnt = 1;

            if(dp[j].count(diff))
                cnt = dp[j][diff];

            dp[i][diff] = 1+cnt;
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

//more faster way
int longestArithSeqLengthOpt(vector<int>& nums) {
    int n = nums.size(), ans = 0;

    vector<vector<int> > dp(n, vector<int>(1005, 1)); //dp[i][j] --> length of subseq end with nums[i-1] and diff j

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            int diff = nums[i]-nums[j];
            dp[i][diff] = 1+dp[j][diff];
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the length of the array  ";
    cin>>n;

    //here the array is strictly increasing
    vector<int> nums;
    cout<<"Enter the elements\n";
    for(int i = 0; i<n; i++)
        cin>>nums[i];

    cout<<"The length of largest AP in given array is "<<longestArithSeqLengthOpt(nums);
 return 0;
}