#include<iostream>
using namespace std;
using ll=long long;

int main(){
    ll n,i;
    cin>>n;
    ll ans=6;
    for(i=11;i<=n;i++)ans*=i;
    cout<<ans;
}