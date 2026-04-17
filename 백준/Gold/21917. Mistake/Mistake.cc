#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll n,m,k;
    ll i,j;
    cin>>n>>m>>k;
    vector<ll>arr(n+1);
    for(i=0;i<k;i++){
        cin>>j>>j;
    }
    for(i=0;i<n*m;i++){
        cin>>j;
        cout<<++arr[j]<<' ';
    }
}