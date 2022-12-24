#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void insertBegining(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertMiddle(Node* &head, Node* &tail, int data, int position){
    if(position == 1){
        insertBegining(head, data);
        return;
    }

    Node* temp = head;
    int i = 1;
    while(i<position-1){
        temp = temp->next;
        i++;
    }

    if(temp->next == NULL){
        insertTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void PrintData(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;
    PrintData(head);
    insertBegining(head, 25);
    insertBegining(head, 20);
    insertBegining(head, 34);
    PrintData(head);
    insertTail(tail, 18);
    insertTail(tail, 38);
    insertTail(tail, 42);
    PrintData(head);
    cout<<"head:- "<<head->data<<endl;
    cout<<"tail:- "<<tail->data<<endl;
    insertMiddle(head, tail, 23, 3);
    insertMiddle(head, tail, 92, 1);
    insertMiddle(head, tail, 80, 10);
    PrintData(head);
    cout<<"head:- "<<head->data<<endl;
    cout<<"tail:- "<<tail->data<<endl;
    deleteNode(1, head);
    deleteNode(9, head);
    deleteNode(5, head);
    PrintData(head);
 return 0;
}