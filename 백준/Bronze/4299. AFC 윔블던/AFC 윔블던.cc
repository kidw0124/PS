#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;cin>>a>>b;
    if((a+b)&1 or a<b)cout<<-1;
    else{
        cout<<(a+b)/2<<' '<<
            (a-b)/2;
        }}