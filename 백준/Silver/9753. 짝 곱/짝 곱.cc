#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()

void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

vector<ll>primes;

void preprocess(){
    vector<bool>chk(100'001);
    for(ll i=2;i<=100'000;i++){
        if(!chk[i])primes.push_back(i);
        for(ll j=i*i;j<=100'000;j+=i){
            chk[j]=1;
        }
    }
}

void solve(ll testcase){
    ll i,j,k;
    ll n,m;
    cin>>n;
    ll ans=n*2 + 1000;
    for(auto k:primes){
        auto p= lower_bound(all(primes),n/k);
        while(*p*k<n||*p==k){
            p++;
        }
        ans=min(ans,*p*k);
    }
    cout<<ans<<'\n';
}

int main() {
    setup();
    preprocess();
    ll t=1;
    cin>>t;
    for(ll testcase=1;testcase<=t;testcase++) {
        solve(testcase);
    }
    return 0;
}
