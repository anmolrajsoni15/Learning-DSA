#include<iostream>
using namespace std;

void printdata(int *arr, int s){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<", ";
    }
    cout<<endl;
}

void selectionSort(int *arr, int s){
    if(s==0 || s == 1)
        return;

    int minindex = 0;
    for (int i = 1; i < s; i++)
    {
        if(arr[i] < arr[minindex])
            minindex = i;
    }
    swap(arr[minindex], arr[0]);

    selectionSort(arr+1, s-1);
    
}

int main(){
    int arr[] = {9,6,89,5,43,21};
    int size = 6;
    cout<<"Your array is :- ";
    printdata(arr, size);
    selectionSort(arr, size);
    cout<<"After sorting the array becomes :- ";
    printdata(arr,size);
 return 0;
}