#include<bits/stdc++.h>
using namespace std;

//MAX HEAP
class heap{
  public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        //step 1:- increase the size by 1;
        size = size+1;
        int index = size;

        //step 2:- put the value in last index
        arr[index] = val;

        //step 3:- take that value in its correct position
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else    return;
        }
    }

    void print(){
        for(int i = 1; i<=size; i++)
            cout<<arr[i]<<' ';
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Your heap is Empty. Nothing to delete."<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftInd = 2*i;
            int rightInd = 2*i + 1;

            if(leftInd < size && arr[i]<arr[leftInd]){
                swap(arr[i], arr[leftInd]);
                i = leftInd;
            }
            else if(rightInd < size && arr[i]<arr[rightInd]){
                swap(arr[i], arr[rightInd]);
                i = rightInd;
            }
            else    return;
        }
    } 
};

int main(){
    heap h;
    h.insert(50);
    h.insert(54);
    h.insert(52);
    h.insert(55);
    h.insert(53);

    h.print();

    h.deleteFromHeap();
    h.print();
 return 0;
}