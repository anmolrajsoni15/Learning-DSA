#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

class compare{
  public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        if(K == 0)
            return NULL;
        
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        for(int i = 0; i<K; i++)
            if(arr[i] != NULL)
                minHeap.push(arr[i]);
                
        Node* head = NULL;
        Node* tail = NULL;
        
        while(!minHeap.empty()){
            Node* top = minHeap.top();
            minHeap.pop();
            
            if(top->next != NULL)
                minHeap.push(top->next);
            
            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }
        
        return head;
    }
};


int main(){

 return 0;
}