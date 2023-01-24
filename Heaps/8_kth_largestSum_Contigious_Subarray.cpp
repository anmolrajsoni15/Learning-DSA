#include<bits/stdc++.h>
using namespace std;

int kthLargestSubarray(vector<int> &arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(pq.size()<k)
                pq.push(sum);
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

int main(){
    int n;
    cout<<"Enter the size of array  ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array\n";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int k;
    cout<<"Enter the value of k  ";
    cin>>k;

    cout<<"The "<<k<<"th largest sum contigious subarray is:- ";
    cout<<kthLargestSubarray(arr, n, k)<<endl;
 return 0;
}