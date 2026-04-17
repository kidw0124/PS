#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,i,j;
    cin>>n;
    vector<ll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    ll m=count_if(arr.begin(),arr.end(),[](ll&x){return x&1;});
    if(m==(n+1)/2)cout<<1;
    else cout<<0;
}
