#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *links[26];

    bool containKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node *get(char ch){
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s){
    int cnt = 0;
    Node *root = new Node();

    for(int i = 0; i<s.size(); i++){
        Node *node = root;
        for(int j = i; j<s.size(); j++){
            if(!node->containKey(s[j])){
                cnt++;
                node->put(s[i], new Node());
            }
            node = node->get(s[i]);
        }
    }

    return cnt+1;
}

int main(){
    string str = "sds";
    cout<<"No. of Distinct Substring of "<<str<<"is "<<countDistinctSubstrings(str)<<endl;
 return 0;
}