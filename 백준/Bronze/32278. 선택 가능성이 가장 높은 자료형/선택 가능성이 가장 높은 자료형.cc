#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n>INT_MAX||n<INT_MIN)cout<<"long long\n";
    else if(n>SHRT_MAX||n<SHRT_MIN)cout<<"int\n";
    else cout<<"short\n";

}