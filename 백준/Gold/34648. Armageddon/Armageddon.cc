#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;

constexpr ll mod=1e9+7;

ll modpow(ll a, ll b,ll m=mod){
    ll ret=1,tmp;
    a%=m;
    b%=m-1;
    tmp=a;
    while(b){
        if(b&1)ret=ret*tmp%m;
        tmp=tmp*tmp%m;
        b>>=1;
    }
    return ret;
}

ll modinv(ll a, ll m=mod){
    return modpow(a,m-2,m);
}

void solve(ll tc){
    ll i,j;
    ll a,b,n;
    cin>>a>>b>>n;
    ll now=1,tmp=1;
    vector<ll>arr;
    arr.reserve(n);
    arr.push_back(0);
    arr.push_back(1);
    while(arr.size()<n){
        if((tmp+2)*b>tmp*a){
            now=now*(tmp+2)%mod*modinv(tmp)%mod;
            arr.push_back(now);
            now=now*(tmp+2)%mod*modinv(tmp)%mod;
            arr.push_back(now);
            tmp++;
        }
        else{
            now=now*a%mod*modinv(b)%mod;
            arr.push_back(now);
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
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
    for(ll tc=1;tc<=t;tc++){
        solve(tc+1);
    }
}