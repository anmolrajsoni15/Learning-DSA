#include<iostream>
using namespace std;

bool isPresent(int *arr, int s, int k){
    if(s==0)
        return false;

    if(arr[0] == k)
        return true;
    else{
        return isPresent(arr+1, s-1, k);
    }
}

int main(){
    int arr[6] = {2, 3, 4, 5, 6, 2};
    int size = 6;
    int key = 2;
    bool ans = isPresent(arr, size, key);

    if(ans)
        cout<<"Your number is present in the array";
    else
        cout<<"Sorry, your number is not present in the array";
 return 0;
}       