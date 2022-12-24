#include<iostream>
#include<string>
using namespace std;

void reverse(string& str, int s, int e){
    if(s>e)
        return;
    swap(str[s], str[e]);
    return reverse(str, s+1, e-1);
    
}

int main(){
    string name = "abcdef";
    int s = 5;
    reverse(name, 0, name.length()-1);
    cout<<"The string after reverse function is : ";
    cout<<name;
 return 0;
}