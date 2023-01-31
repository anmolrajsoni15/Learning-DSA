#include<bits/stdc++.h>
using namespace std;

//Recursive Approach
int fibonacci(int n){
    if(n <= 1)
        return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

//Memoization
int fibMemo(int n, vector<int> &dp){
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fibMemo(n-1, dp)+fibMemo(n-2, dp);
}

void fibTab(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
}

int fibSpaceOptimise(int n){
    int prev1 = 1;
    int prev2 = 0;

    for(int i = 2; i<=n; i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n;
    cout<<"Enter the value:- ";
    cin>>n;

    // for recursive approach
    cout<<"The "<<n<<"th fibonacci number is:- "<<fibonacci(n)<<endl;

    //using memoization
    vector<int> dp(n+1, -1);
    cout<<"The "<<n<<"th fibonacci number is:- "<<fibMemo(n, dp)<<endl;

    //using tabulation
    vector<int> newDp(n+1);
    fibTab(n, newDp);
    cout<<"The "<<n<<"th fibonacci number is:- "<<newDp[n]<<endl;

    //using space optimisation
    cout<<"The "<<n<<"th fibonacci number is:- "<<fibSpaceOptimise(n)<<endl;
 return 0;
}