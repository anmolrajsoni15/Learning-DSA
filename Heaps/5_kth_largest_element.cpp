#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the size of array and kth element\n";
    int n, k;  cin>>n>>k;
    cout<<"Enter the elemets in the array:-\n";
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    priority_queue<int> pq;
    for(int i = 0; i<k; i++)
        pq.push(arr[i]);

    for(int i = k; i<n; i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout<<"The "<<k<<"th smallest element in the array is ";
    cout<<pq.top()<<endl;

 return 0;
}