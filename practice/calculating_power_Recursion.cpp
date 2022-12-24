#include<iostream>
using namespace std;

long long power(int n, int m){
    if(m==0)
        return 1;
    if(m==1)
        return n;

    int ans = power(n, m/2);
    if(m%2 == 0)
        return ans*ans;
    else
        return n*ans*ans;
}

int main(){
    cout<<"Find the value of 2^6 "<<endl;
    cout<<"The value of 2^6 is : "<<power(2, 30);
 return 0;
}