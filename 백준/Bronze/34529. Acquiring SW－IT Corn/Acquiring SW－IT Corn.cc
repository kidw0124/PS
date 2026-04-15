#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main(){
    ll a,b,c,x,y,z;
    cin>>x>>y>>z>>a>>b>>c;
    cout<<(a+100-1)/100*x
        +(b+50-1)/50*y
        +(c+20-1)/20*z;
    
}