#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data)
        root->right = insertIntoBST(root->right, d);
    if(d < root->data)
        root->left = insertIntoBST(root->left, d);

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }

    if(data == -1)  return;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<front->data<<' ';
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }

    }
    cout<<endl;
}

//Apporach 1:- Space Complexitiy O(m+n)
// Using array for extra space
void inOrder(Node* root, vector<int> &in){
    if(root == NULL)    return;
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

vector<int> mergeArray(vector<int> &bst1, vector<int> &bst2){
    vector<int> ans;

    int i = 0, j = 0;
    while(i<bst1.size() && j<bst2.size()){
        if(bst1[i]<bst2[j]){
            ans.push_back(bst1[i]);
            i++;
        }
        else{
            ans.push_back(bst2[j]);
            j++;
        }
    }

    while(i<bst1.size()){
        ans.push_back(bst1[i]);
        i++;
    }

    while(j<bst2.size()){
        ans.push_back(bst2[j]);
        j++;
    }

    return ans;
}

Node* inOrderToBST(vector<int> &arr, int s, int e){
    if(s>e) return NULL;

    int mid = s + (e-s)/2;
    Node *root = new Node(arr[mid]);
    root->left = inOrderToBST(arr, s, mid-1);
    root->right = inOrderToBST(arr, mid+1, e);

    return root;
}

Node* mergeBST(Node* root1, Node* root2){
    //step 1:- create two sorted arrays from bst
    vector<int> bst1, bst2;
    inOrder(root1, bst1);
    inOrder(root2, bst2);

    //step 2:- Merge that two sorted bst arrays
    vector<int> mergedArray = mergeArray(bst1, bst2);

    //step 3:- Convert that sorted inOrder array to BST
    int s = 0, e = mergedArray.size()-1;
    return inOrderToBST(mergedArray, s, e);
}

//Approach 2:- Space Complexitiy O(h1+h2)
//without using extra space i.e. using the same root, converting into DLL and then merging
void convertIntoSortedDLL(Node* root, Node* &head){
    if(root == NULL)    return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;
    convertIntoSortedDLL(root->left, head);
}

Node* mergeSortedDLL(Node* head1, Node* head2){
    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;    
    }

    return head;
}

int countNodes(Node* &head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* sortedDLLtoBST(Node* &head, int n){
    if(n<=0 || head == NULL)
        return NULL;

    Node* left = sortedDLLtoBST(head, n/2);
    Node* root = head;
    root->left = left;

    head = head->right;

    root->right = sortedDLLtoBST(head, n-n/2-1);

    return root;
}

Node* mergeBSTnew(Node* root1, Node* root2){
    //Step 1:- Convert the bsts into DLL
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //Step 2:- Merge two sorted DLL to create new sorted DLL
    Node* head = mergeSortedDLL(head1, head2);

    //Step 3:- Convert the sorted DLL to BST
    return sortedDLLtoBST(head, countNodes(head));
}

int main(){
    Node* root1 = NULL;
    cout<<"Enter data to create first BST :- "<<endl;
    takeInput(root1);

    Node* root2 = NULL;
    cout<<"Enter data to create second BST :- "<<endl;
    takeInput(root2);

    //Approach 1:-
    Node* root = mergeBST(root1, root2);
    cout<<"The merged Bst is through first Approach is:-\n";
    levelOrderTraversal(root);

    //Approach 2:-
    Node* newroot = mergeBSTnew(root1, root2);
    cout<<"The merged Bst is through second Approach is:-\n";
    levelOrderTraversal(newroot);
 return 0;
}