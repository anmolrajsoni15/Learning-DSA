#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int s , int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];

    long long sum1 = 0, sum2 = 0;
    int mainIndex = s;
    for (int i = 0; i < len1; i++){
        first[i] = arr[mainIndex++];
        sum1 += first[i];
    }

    mainIndex = mid+1;
    for (int i = 0; i < len2; i++){
        second[i] = arr[mainIndex++];
        sum2 += second[i];
    }

    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    cout<<len1<<' '<<len2<<endl;
    if(len1 == 1 && len2 == 1){
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2])
                arr[mainIndex++] = first[index1++];
            else
                arr[mainIndex++] = second[index2++];
        }
        while(index1 < len1){
            arr[mainIndex++] = first[index1++];
        }
        while(index2 < len2){
            arr[mainIndex++] = second[index2++];
        }
    }
    else{
        if(sum1>sum2){
            // while(index1 < len1 && index2 < len2){
            //     arr[mainIndex++] = second[index2++];
            // }
            while(index2 < len2){
                arr[mainIndex++] = second[index2++];
            }
            while(index1 < len1){
                arr[mainIndex++] = first[index1++];
            }
        }
        else{
            while(index1 < len1){
                arr[mainIndex++] = first[index1++];
            }
            while(index2 < len2){
                arr[mainIndex++] = second[index2++];
            }
        }
    }
}

void mergeSort(int *arr, int s, int e){
    //base case
    if(s >= e)
        return;
    
    int mid = s+(e-s)/2;

    //left part
    mergeSort(arr, s, mid);
    //right part
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main(){
    int arr[8] = {6,5,7,8,4,3,1,2};
    int size = 8;

    mergeSort(arr, 0, size-1);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
 return 0;
}