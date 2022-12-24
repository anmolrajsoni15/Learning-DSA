#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string a = "0";
    string b = "0";

    int sum = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[a.length()-1-i] == '1'){
            sum = sum + pow(2,i);
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if(b[b.length()-1-i] == '1'){
            sum = sum + pow(2,i);
        }
    }
    cout<<sum;
    int x = sum;
    string c;
    while(sum){
        if(sum%2 == 0)
            c.push_back('0');
        else
            c.push_back('1');
        sum = sum>>1;
    }
    
    for (int i = 0; i < c.length(); i++)
    {
        cout<<c[c.length()-i-1];
    }
    
 return 0;
}