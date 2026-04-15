#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll f(ll x){return x>0?x*(x+1)/2:-x*(x-1)/2;}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<(a+b)*(abs(b-a)+1)/2;
}