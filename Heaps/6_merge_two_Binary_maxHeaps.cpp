#include<bits/stdc++.h>
using namespace std;

    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i + 2;
        
        if(left<n && arr[largest]<arr[left])
            largest = left;
        if(right<n && arr[largest]<arr[right])
            largest = right;
            
        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(int i : a)
            ans.push_back(i);
        for(int i : b)
            ans.push_back(i);
            
        for(int i = ans.size()/2 - 1; i>=0; i--)
            heapify(ans, ans.size(), i);
            
        return ans;
    }

int main(){
    int n;
    vector<int> heap1, heap2;
    cout<<"Enter the size of Heap 1 :- ";
    cin>>n;
    cout<<"Enter the data of first Heap\n";
    for(int i = 0; i<n; i++){
        int x;  cin>>x;
        heap1.push_back(x);
    }

    int m;
    cout<<"Enter the size of Heap 2 :- ";
    cin>>m;
    cout<<"Enter the data of first Heap\n";
    for(int i = 0; i<m; i++){
        int x;  cin>>x;
        heap2.push_back(x);
    }

    vector<int> heap;
    heap = mergeHeaps(heap1, heap2, n, m);
    cout<<"The merged heap is:-\n";
    for(auto it: heap)
        cout<<it<<' ';
    cout<<endl;

 return 0;
}