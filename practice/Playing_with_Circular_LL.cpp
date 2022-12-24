#include<iostream>
#include<map>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert_Head(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insert_Tail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void PrintData(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    cout<<endl;
}

bool DetectLoop(Node* head){
    if(head == NULL)
        return false;

    Node* temp = head;
    map<Node*, bool> visited;
    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"The loop starts from element:- "<<temp->data<<endl;
            return 1;
        }
        visited[temp] = 1;
        temp = temp->next;
    }
    return false; 
}

Node* FloydCycleLoop(Node* head){
    if(head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

int main(){
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;

    insert_Head(head, 20);
    insert_Head(head, 90);
    insert_Head(head, 50);
    insert_Head(head, 40);

    insert_Tail(tail, 28);
    insert_Tail(tail, 39);
    insert_Tail(tail, 27);

    PrintData(head);

    tail->next = head->next->next;

    if(DetectLoop(head)){
        cout<<"Loop is Present in the LinkedList"<<endl;
    }
    else
        cout<<"Loop is not Present in the LinkedList"<<endl;

    cout<<"\n \t-----Using Flyod Cycle Loop----"<<endl;
    if(FloydCycleLoop(head) != NULL){
        cout<<"Loop is Present in the LinkedList"<<endl;
    }
    else
        cout<<"Loop is not Present in the LinkedList"<<endl;

 return 0;
}