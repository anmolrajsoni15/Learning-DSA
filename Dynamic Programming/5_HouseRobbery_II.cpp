#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int take = prev2 + nums[i];
        int notTake = prev1;
        int ans = max(take, notTake);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    vector<int> arr1, arr2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr2.push_back(nums[i]);
        if (i != n - 1)
            arr1.push_back(nums[i]);
    }

    return max(solve(arr1), solve(arr2));
}

int main()
{
    int n;
    cout<<"Enter the size:- ";
    cin>>n;

    vector<int> nums;
    cout<<"Enter the value of circular array:-";
    for(int i = 0; i<nums.size(); i++)
        cin>>nums[i];

    cout<<"The maximum amount the theif can rob without alerting the police is "<<rob(nums)<<endl;

    return 0;
}