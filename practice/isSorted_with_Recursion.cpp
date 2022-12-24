#include <iostream>
using namespace std;

// void printvalue(int *arr, int s){
//     for (int i = 0; i < s; i++)
//     {
//         cout<<arr[i]<<' ';
//     }
//     cout<<endl;
// }

bool isSorted(int*arr, int s){
    // printvalue(arr, s);    ---->  just to check how recursion works
    if(s==1 || s==0){
        return true;
    }

    if(arr[0]>arr[1])
        return false;
    else{
        return isSorted(arr+1, s-1);
    }
}

int main()
{
    int arr[5] = {2, 3, 4, 7, 6};
    int size = 5;
    cout<<isSorted(arr, size);

    return 0;
}