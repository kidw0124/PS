#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,t;
    cin>>a>>c>>b>>t;
    if(t<=30)cout<<a;
    else cout<<a+(t-30+c-1)/c*b;
}