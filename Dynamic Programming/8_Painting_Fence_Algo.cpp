#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int add(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}

int mul(int a, int b){
    return ((a%mod)*1LL*(b%mod))%mod;
}

//using recursion
int numberOfWaysRec(int n, int k){
    if(n == 1)
        return k;

    if(n == 2)
        return add(k, mul(k, k-1));

    return add(mul(numberOfWaysRec(n-2, k), k-1), mul(numberOfWaysRec(n-1, k), k-1));
}

//using memoisation
int solveMemo(int n, int k, vector<int> &dp){
    if(n == 1)
        return k;

    if(n == 2)
        return add(k, mul(k, k-1));

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = add(mul(solveMemo(n-2, k, dp), k-1), mul(solveMemo(n-1, k, dp), k-1));
}

int numberOfWaysMemo(int n, int k){
    vector<int> dp(n+1, -1);
    return solveMemo(n, k, dp);
}

//using tabulation
int numberOfWaysTab(int n, int k){
    vector<int> dp(n+1);

    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i = 3; i<=n; i++){
        int one = mul(dp[i-1], k-1);
        int two = mul(dp[i-2], k-1);
        dp[i] = add(one, two);
    }

    return dp[n];
}

//using space optimisation
int numberOfWaysOpt(int n, int k){

    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i = 3; i<=n; i++){
        int one = mul(prev2, k-1);
        int two = mul(prev1, k-1);
        int curr = add(one, two);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n, k;
    cout<<"Enter the number of poles in the Fence  ";
    cin>>n;
    cout<<"Enter the number of colors  ";
    cin>>k;

    //using recursion
    cout<<"No. of ways to paint poles with at most two consecutive cells of same color is "<<numberOfWaysRec(n, k)<<endl;

    //using memoisation
    cout<<"No. of ways to paint poles with at most two consecutive cells of same color is "<<numberOfWaysMemo(n, k)<<endl;

    //using tabulation
    cout<<"No. of ways to paint poles with at most two consecutive cells of same color is "<<numberOfWaysTab(n, k)<<endl;

    //using space optimisation
    cout<<"No. of ways to paint poles with at most two consecutive cells of same color is "<<numberOfWaysOpt(n, k)<<endl;
 return 0;
}