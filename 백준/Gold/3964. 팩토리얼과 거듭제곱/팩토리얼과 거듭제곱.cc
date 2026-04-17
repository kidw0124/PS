#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}


int main(){
    setup();
    ll t,n,m,i,j,k;
    cin>>t;
    vector<ll>primes;
    vector<bool>isprime(1'000'006);
    for(i=2;i<1'000'006;i++){
        if(!isprime[i]){
            primes.push_back(i);
            for(j=i*i;j<1'000'006;j+=i){
                isprime[j]=1;
            }
        }
    }
    while(t--){
        cin>>n>>m;
        ll cnt=LLONG_MAX;
        map<ll,ll>factor;
        for(i=0;i<primes.size();i++){
            while(m%primes[i]==0){
                factor[primes[i]]++;
                m/=primes[i];
            }
        }
        if(m>1){
            factor[m]=1;
        }
        for(auto [p,c]:factor){
            ll tmp=n;
            ll d=0;
            while(tmp){
                d+=tmp/=p;
            }
            cnt=min(d/c,cnt);
        }
        cout<<cnt<<'\n';
    }
}