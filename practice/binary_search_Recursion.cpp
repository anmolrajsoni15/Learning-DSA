#include<iostream>
using namespace std;

int binarySearch(int *arr, int s, int e, int k){
    if(s>e){
        cout<<"Not found"<<endl;
        return -1;
    }
    int mid = s+(e-s)/2;

    if(arr[mid] == k)
        return mid;
    if(arr[mid] < k)
        return binarySearch(arr, mid+1, e, k);
    else
        return binarySearch(arr, s, mid-1, k);
}

int main(){
    int array[8] = {1,4,6,34,56,67,89,101};
    int size = 8;
    cout<<"The index of your key is : "<<binarySearch(array, 0, size-1, 9);
 return 0;
}