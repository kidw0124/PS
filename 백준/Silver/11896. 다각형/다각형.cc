#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n){
    return n*(n+1)/2;
}
int main(){
    ll a,b;
    cin>>a>>b;
    a=max(3ll,a-1);
    b=max(3ll,b);
    cout<<2*(f(b/2)-f(a/2));
    }