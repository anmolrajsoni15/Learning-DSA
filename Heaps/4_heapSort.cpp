#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
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

void heapSort(vector<int> &arr, int n){
    int size = n-1;

    for (int i = size; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){

    int n;
    cout<<"Enter the size of Array:- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array\n";
    for(int i = 0; i< n; i++)
        cin>>arr[i];

    for(int i = n/2-1; i>=0; i--)
        heapify(arr, n, i);

    heapSort(arr, n);

    cout<<"The sorted array is\n";
    for(int i = 0; i< n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
 return 0;
}