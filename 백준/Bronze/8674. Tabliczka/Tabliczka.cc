#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll a,b;
    cin>>a>>b;
    if(a%2==1 && b%2==1)cout<<min(a,b);
    else cout<<0;
}