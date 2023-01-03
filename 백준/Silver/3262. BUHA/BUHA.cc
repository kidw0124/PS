#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
    setup();
    ll i,j;
    ll a,b,k;
    cin>>a>>b>>k;
    vector<vector<bool>>arr(a,vector<bool>(b));
    vector<tuple<ll,ll,ll,ll>>brr(k);
    for(i=0;i<k;i++){
        ll r,s,p,t;
        cin>>r>>s>>p>>t;
        brr[i]={r-1,s-1,p,t};
    }
    std::sort(brr.begin(), brr.end(),[](auto&a,auto&b) {
        return get<3>(a) > get<3>(b);
    });
    ll en= std::find_if(brr.begin(), brr.end(),[](auto& k){
        return get<3>(k)==0;
    })-brr.begin();
    vector<ll>aq,aw,ae,ar;
    aq.push_back(0);
    aw.push_back(a-1);
    ae.push_back(0);
    ar.push_back(b-1);
    for(i=0;i<en;i++){
        auto [r,s,p,t]=brr[i];
        aq.push_back(r-p/2);
        aw.push_back(r+p/2);
        ae.push_back(s-p/2);
        ar.push_back(s+p/2);
    }
    std::sort(aq.begin(), aq.end());
    std::sort(aw.begin(), aw.end());
    std::sort(ae.begin(), ae.end());
    std::sort(ar.begin(), ar.end());
    debugc(aq)
    debugc(aw)
    debugc(ae)
    debugc(ar)
    for(i=aq[en];i<=aw[0];i++){
        for(j=ae[en];j<=ar[0];j++){
            arr[i][j]=1;
        }
    }
    for (int l = 0; l < a; ++l) {
        debugc(arr[l]);
    }
    for(i=en;i<k;i++){
        auto [r,s,p,t]=brr[i];
        for(j=max(0ll,r-p/2);j<=min(a-1,r+p/2);j++){
            for(t=max(0ll,s-p/2);t<=min(b-1,s+p/2);t++){
                arr[j][t]=0;
            }
        }
    }
    for (int l = 0; l < a; ++l) {
        debugc(arr[l]);
    }
    ll ans=0;
    for(i=0;i<a;i++){
        ans+=std::count(arr[i].begin(), arr[i].end(),1);
    }
    cout<<ans;
}