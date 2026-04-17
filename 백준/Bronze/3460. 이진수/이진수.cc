#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        while(n){
            cout<<__builtin_ctz(n)<<' ';
            n&=n-1;
        }
        cout<<'\n';
    }
}