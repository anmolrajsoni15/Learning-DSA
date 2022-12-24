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

};

void insertBegining(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void PrintData(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverseLinkedList_1(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

Node* reverseLinkedList_2(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}

Node* reverseLinkedList_3(Node *head)
{
    // Write your code here
	if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* New = reverseLinkedList_3(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return New;
}

int main(){
Node* node1 = new Node(10);
Node* head = node1;

    insertBegining(head, 25);
    insertBegining(head, 20);
    insertBegining(head, 34);
    PrintData(head);


Node* reversed_2 = reverseLinkedList_2(head);
    PrintData(reversed_2);
    
Node* reversed_1 = reverseLinkedList_1(head);
    PrintData(reversed_1);
 return 0;
}