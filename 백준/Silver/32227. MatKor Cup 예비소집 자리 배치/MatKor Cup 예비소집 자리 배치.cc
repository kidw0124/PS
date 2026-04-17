#include<bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll mod=1e9+7;

ll inverse(ll a){

    ll b=mod-2;

    ll res=1;

    while(b){

        if(b&1)res=res*a%mod;

        a=a*a%mod;

        b>>=1;

    }

    return res;

}

void solve(){

    ll i,j;

    ll n,m;

    cin>>n>>m;

    ll g=gcd(n,m);

    cout<<n/g<<'/'<<m/g<<'\n';

}

int main(){

#ifdef kidw0124

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

#else

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

#endif

    ll t=1;

//    cin>>t;

    while(t--)solve();

}