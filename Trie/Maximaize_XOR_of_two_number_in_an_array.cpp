#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* links[2];

    bool containKey(int bit){
        return links[bit] != NULL;
    }

    Node *get(int bit){
        return links[bit];
    }

    void put(int bit, Node *node){
        links[bit] = node;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containKey(bit))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node *node = root;
        int maxNum = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }

        return maxNum;
    }
};

int maxXor(int n, int m, vector<int> &arr1, vector<int> &arr2){
    Trie trie;
    for(auto &it : arr1)
        trie.insert(it);
    int maxi = 0;
    for(auto &it : arr2)
        maxi = max(maxi, trie.getMax(it));
    
    return maxi;
}

int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr2 = {5, 6, 7, 8, 9};

    cout<<"The maximum xor of any two elements from the array 1 and array 2 is ";
    cout<<maxXor(7, 5, arr1, arr2)<<endl;
 return 0;
}