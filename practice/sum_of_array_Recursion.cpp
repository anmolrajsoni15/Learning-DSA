#include<iostream>
using namespace std;

int arraySum(int *arr, int s){
    if(s == 0)
        return 0;
    if(s == 1)
        return arr[0];
    return (arr[0] + arraySum(arr+1, s-1));
}

int main(){
    int arr[6] = {2, 3, 4, 5, 6, 2};
    int size = 6;
    cout<<"The sum of the values in array is :- "<< arraySum(arr, size);
 return 0;
}