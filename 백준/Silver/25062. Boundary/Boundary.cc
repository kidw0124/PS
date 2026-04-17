#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll gcd(ll a, ll b){
    if(b)return gcd(b,a%b);
    else return a+b;
}

ll gcd(ll a, ll b, ll c){
    return gcd(gcd(a,b),c);
}

void solve()
{
    ll i,j;
    ll n, m;
    cin>>n>>m;
    set<ll>ans;
    ll g=gcd(n,m-2);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            ans.insert(i);
            ans.insert(g/i);
        }
    }
    g=gcd(n-2,m);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            ans.insert(i);
            ans.insert(g/i);
        }
    }
    g=gcd(n-1,m-1);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            ans.insert(i);
            ans.insert(g/i);
        }
    }
    g=gcd(n,n-2,m-1);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            ans.insert(i);
            ans.insert(g/i);
        }
    }
    g=gcd(m,m-2,n-1);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            ans.insert(i);
            ans.insert(g/i);
        }
    }
    cout<<ans.size()<<' ';
    for(auto k:ans)cout<<k<<' ';cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)solve();
    return 0;
}