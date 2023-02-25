#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long x=1;
    while(n){
        x*=n;
        n--;
    }
    cout<<x;
}