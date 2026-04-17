#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,kf=1000000000,m=-99999;
stack<ll> brr;
stack<ll>arr;
void func(ll a, ll b, ll c, ll d, stack<ll> ee){
    if(ee.size()==1){
        kf=min(kf,ee.top());
        m=max(m,ee.top());
    }
    ll k=ee.top();
    ee.pop();
    if(a){
        stack<ll>e=ee;
        ll x=e.top()+k;
        e.pop();
        e.push(x);
        func(a-1,b,c,d,e);
    }
    if(b){
        stack<ll>e=ee;
        ll x=k-e.top();
        e.pop();
        e.push(x);
        func(a,b-1,c,d,e);
    }
    if(c){
        stack<ll>e=ee;
        ll x=k*e.top();
        e.pop();
        e.push(x);
        func(a,b,c-1,d,e);
    }
    if(d){
        stack<ll>e=ee;
        ll x=k/e.top();
        e.pop();
        e.push(x);
        func(a,b,c,d-1,e);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    int p,q,r,s;
    for(i=0;i<n;i++){cin>>j;arr.push(j);}
    while(!arr.empty()){
        brr.push(arr.top());
        arr.pop();
    }
    cin>>p>>q>>r>>s;
    func(p,q,r,s,brr);
    cout<<m<<'\n'<<kf;
    return 0;
}
