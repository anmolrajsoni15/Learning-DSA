#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

//using recursion
long long countRec(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    int ans = ((n-1)%MOD * (countRec(n-1)%MOD + countRec(n-2)%MOD))%MOD;
    return ans;
}

//using memoisation
long long solveMemo(int n, vector<long long> &dp){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = ((n-1)%MOD * (solveMemo(n-1, dp)%MOD + solveMemo(n-2, dp)%MOD))%MOD;
    return dp[n] = ans;
}

long long countMemo(int n){
    vector<long long> dp(n+1, -1);
    return solveMemo(n, dp);
}

//using tabulation
long long countTab(int n){
    vector<long long> dp(n+1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i<=n; i++){
        long long first = dp[i-1]%MOD;
        long long second = dp[i-2]%MOD;
        long long sum = (first+second)%MOD;

        long long ans = ((i-1)*sum)%MOD;
        dp[i] = ans;
    }

    return dp[n];
}

//using space optimisation
long long countOpt(int n){
    long long prev2 = 0;
    long long prev1 = 1;

    for(int i = 3; i<=n; i++){
        long long first = prev2%MOD;
        long long second = prev1%MOD;
        long long sum = (first+second)%MOD;

        long long ans = ((i-1)*sum)%MOD;

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    int n;
    cout<<"Enter the size of permutation"<<endl;
    cin>>n;

    //using recursion
    cout<<"Total number of ways such that none of the elements are in their original place is "<<countRec(n)<<endl;

    //using memoisation
    cout<<"Total number of ways such that none of the elements are in their original place is "<<countMemo(n)<<endl;

    //using tabulation
    cout<<"Total number of ways such that none of the elements are in their original place is "<<countTab(n)<<endl;

    //using space optimisation
    cout<<"Total number of ways such that none of the elements are in their original place is "<<countOpt(n)<<endl;

 return 0;
}