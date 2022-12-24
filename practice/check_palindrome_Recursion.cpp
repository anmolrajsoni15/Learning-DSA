#include<iostream>
using namespace std;

bool checkPalindrome(string str, int s, int e){
    if(s>e)
        return true;
    if(str[s]!=str[e])
        return false;
    else
        return checkPalindrome(str, s+1, e-1);
}

int main(){
    string pal = "wow";
    bool check = checkPalindrome(pal, 0, pal.length()-1);
    if(check)
        cout<<"Your string is a palindrome"<<endl;
    else
        cout<<"Your string is not a palindrome"<<endl;
 return 0;
}