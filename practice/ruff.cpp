#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 2, 4, 6, 7, 9};
    int x = lower_bound(arr.begin(), arr.end(), 4)-arr.begin();
    cout<<x<<endl;
 return 0;
}