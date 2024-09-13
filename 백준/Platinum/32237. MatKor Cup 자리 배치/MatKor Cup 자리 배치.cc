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
    vector<ll> facto(m+1),invfacto(m+1);
    facto[0]=1;
    for(i=1;i<=m;i++)facto[i]=facto[i-1]*i%mod;
    invfacto[m]=inverse(facto[m]);
    for(i=m-1;i>=0;i--)invfacto[i]=invfacto[i+1]*(i+1)%mod;
    vector<int>hrr(n+1);
    auto ncr=[&](ll a,ll b){
        if(a<b)return 0ll;
        return facto[a]*invfacto[b]%mod*invfacto[a-b]%mod;
    };
    auto npr=[&](ll a,ll b){
        if(a<b)return 0ll;
        return facto[a]*invfacto[a-b]%mod;
    };
    ll div=inverse(npr(m,n));
    hrr[0]=1,hrr[1]=m-n;
    for(i=2;i<=n;i++){
        hrr[i]=((i-1)*(ll)hrr[i-2]+(i-1+m-n)*(ll)hrr[i-1])%mod;
    }
    for(i=0;i<=n;i++){
        cout<<ncr(n,i)*(ll)hrr[n-i]%mod*div%mod<<' ';
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
    while(t--)solve();
}
