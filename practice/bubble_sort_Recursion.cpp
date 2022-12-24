#include<iostream>
using namespace std;

void printdata(int *arr, int s){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void bubbleSort(int *arr, int s){
    if(s==0 || s == 1)
        return;
    for (int i = 0; i < s-1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    bubbleSort(arr, s-1);
}

int main(){
    int arr[] = {3,6,89,5,43,21};
    int size = 6;
    cout<<"Your array is :- ";
    printdata(arr, size);
    bubbleSort(arr, size);
    cout<<"After sorting the array becomes :- ";
    printdata(arr,size);
 return 0;
}