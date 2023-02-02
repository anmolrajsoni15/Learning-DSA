#include<bits/stdc++.h>
using namespace std;

//recursive approach
int solve1(int n, int x, int y, int z){
    if(n == 0)
        return 0;

    if(n < 0)
        return INT_MIN;

    int first = solve1(n-x, x, y, z)+1;
    int second = solve1(n-y, x, y, z)+1;
    int third = solve1(n-z, x, y, z)+1;

    return max(first, max(second, third));
}

int cutSegRec(int n, int x, int y, int z){
    int ans = solve1(n, x, y, z);
    if(ans<0)
        return 0;
    else    return ans;
}

//using memoization
int solve2(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0)
        return 0;

    if(n < 0)
        return INT_MIN;

    if(dp[n] != -1)
        return dp[n];

    int first = solve1(n-x, x, y, z)+1;
    int second = solve1(n-y, x, y, z)+1;
    int third = solve1(n-z, x, y, z)+1;

    return dp[n] = max(first, max(second, third));
}

int cutSegMemo(int n, int x, int y, int z){
    vector<int> dp(n+1, -1);
    int ans = solve2(n, x, y, z, dp);
    if(ans<0)
        return 0;
    else    return ans;
}

//using tabulation
int cutSegTab(int n, int x, int y, int z){
    vector<int> dp(n+1, INT_MIN);

    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        if(i-x >= 0)
            dp[i] = max(dp[i], dp[i-x]+1);
        if(i-y >= 0)
            dp[i] = max(dp[i], dp[i-y]+1);
        if(i-z >= 0)
            dp[i] = max(dp[i], dp[i-z]+1);
    }

    if(dp[n] < 0)
        return 0;
    else    return dp[n];
}

int main(){
    int n, x, y, z;
    cout<<"Enter the length of rod:- ";
    cin>>n;

    cout<<"Enter the length of segments\n";
    cin>>x>>y>>z;

    //using recursion
    cout<<"Maximum number of segments will be:- "<<cutSegRec(n, x, y, z)<<endl;

    //using memoization
    cout<<"Maximum number of segments will be:- "<<cutSegMemo(n, x, y, z)<<endl;

    //using tabulation
    cout<<"Maximum number of segments will be:- "<<cutSegTab(n, x, y, z)<<endl;
 return 0;
}