#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll gcd(ll x, ll y) {
    if(y == 0)return x;
    return gcd(y, x % y);
}

void solve() {
    ll i,j;
    ll w,h;
    ll need=0;
    cin>>w>>h;
    for(i=0;i<w;i++){
        ll x;
        cin>>x;
        if(h<x){
            cout<<"impossible\n";
            return;
        }
        else if(h-x<need){
            cout<<"impossible\n";
            return;
        }
        if(need%2!=(h-x)%2){
            need++;
        }
        else need=max(need-1,0ll);
    }
    if(need)cout<<"impossible";
    else cout<<"possible";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();
    return 0;
}