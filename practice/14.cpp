// 2-D Arrays


#include<iostream>
using namespace std;

void getData(int arr[][4], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
}

void showData(int arr[][4], int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][4];
    cout<<"Enter your elements here:- "<<endl;
    getData(arr, 3, 4);
    cout<<"The elements are :-"<<endl;
    showData(arr, 3, 4);

 return 0;
}