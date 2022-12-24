#include<iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[index], arr[parent]);
            }
            else
                return;
        }
    }

    void deleteHeap(){
        if(size == 0){
            cout<<"heap is empty";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int left = 2*i;
            int right = 2*i+1;

            if(left<size && arr[i]<arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right<size && arr[i]<arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                return;
        }
    }

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
    }
};


void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest]<arr[left])
        largest = left;
    if(right<n && arr[largest]<arr[right])
        largest = right;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){
    heap p;
    p.insert(50);
    p.insert(55);
    p.insert(53);
    p.insert(52);
    p.insert(54);

    p.print();
    p.deleteHeap();
    p.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }
    cout<<"Array after Heapify:-\n";
    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
 return 0;
}