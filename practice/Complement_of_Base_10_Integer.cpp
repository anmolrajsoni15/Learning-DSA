#include<iostream>
using namespace std;

int bitwiseCompliment(int n){
    int m = n;
    int mask = 0;
    if(n == 0)
        return 1;
    while(m != 0){
        mask = (mask<<1) | 1;
        m = m>>1;
    }
    return mask & (~n);
}

int main(){
    int n = 7;
    cout<<bitwiseCompliment(n);
 return 0;
}