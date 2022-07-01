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
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll _pow(ll a, int n) {
    if (n <= 1) return n % 2 ? a : 1;
    ll h = _pow(a, n >> 1);
    return h * h * (n % 2 ? a : 1);
}
ll n,brr[63];
ll big(ll n, ll k, ll m){
    ll s=1,e=m,mid;
    while(s<=e){
        mid=(s+e)/2;
        if((ll)_pow(mid,k)<n)s=mid+1;
        else e=mid-1;
    }
    return s;
}

ll small(ll k){
    ll s=1;
    ll e=(1LL<<40);
    ll mid;
    while(s<=e){
        mid=(s+e)/2;
        if(k*log(mid)+1e-9<=log((1ULL<<63)-1))s=mid+1;
        else e=mid-1;
    }
    return e;
}
map<ll,ll>arr;
ll func(ll k) {
    if(arr.find(k)==arr.end()) {
        arr[k]=k-1;
        if(k==1)return arr[k];
        ll s,b;
        for(ll i=2;i<=62;i++) {
            b=big(k,i,brr[i]);
            s=b-1;
            if(1<s&&(ll)2e9>(ll)abs(k-(ll)_pow(s,i)))arr[k]=min(arr[k],(ll)abs(k-(ll)_pow(s,i))+func(s)+1);
            if(1<b&&(ll)2e9>(ll)abs(k-(ll)_pow(b,i)))arr[k]=min(arr[k],(ll)abs(k-(ll)_pow(b,i))+func(b)+1);
        }
    }
    return arr[k];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=2;i<=62;i++)brr[i]=small(i);
    cout<<func(n);

    return 0;
}
