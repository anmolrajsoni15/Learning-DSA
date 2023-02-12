#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int d) {
    unordered_map<int, int> dp;

    int ans = 0;
    for(int i = 0; i<arr.size(); i++){
        int temp = arr[i] - d;
        int tempAns = 0;

        if(dp.count(temp))
            tempAns = dp[temp];

        dp[arr[i]] = 1+tempAns;
        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the length of the array  ";
    cin>>n;

    //here the array is strictly increasing
    vector<int> arr;
    cout<<"Enter the elements\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int difference;
    cout<<"Enter the comman difference of the array:- ";
    cin>>difference;

    cout<<"The length of longest subsequence with comman difference "<<difference<<" is "<<longestSubsequence(arr, difference)<<endl;

 return 0;
}