#include<iostream>
using namespace std;

int reverseInt(int n){
    int x = 0;
    while(n!=0){
        int digit = n%10;
        if(n > INT32_MAX || n < INT32_MIN)
            return 0;
        x = (x*10)+digit;
        n/=10;
    }
    return x;
}

int main(){
    int n = 5670;
    cout<<INT8_MAX<<endl;
    cout<<INT16_MAX<<endl;
    cout<<INT32_MAX<<endl;
    cout<<INT64_MAX<<endl;
    cout<<"The number is :- "<<n<<endl;
    reverseInt(n);
    cout<<"The reversed number is :- "<<reverseInt(n)<<endl;

 return 0;
}