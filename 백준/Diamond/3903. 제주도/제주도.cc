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
typedef long double ld;
typedef long double LD;
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
pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}
// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}
ll mod=998244353;
LD eps=1e-9;

struct line{
    LD a,b,c;
};


void solve(){
    ll i,j;
    ll t;
    while(1){
        ll n;
        cin>>n;
        if(n==0)break;
        vector<pll>arr(n);
        vector<line>brr(n);
        for(i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        for(i=0;i<n;i++){
            brr[i].a=arr[(i+1)%n].second-arr[i].second;
            brr[i].b=-(arr[(i+1)%n].first-arr[i].first);
            brr[i].c=(arr[(i+1)%n].first-arr[i].first)*arr[i].second
                    -(arr[(i+1)%n].second-arr[i].second)*arr[i].first;
        }
        ld st=0,en=10000;
        while(st+eps<en){
            ll x=0,y=0;
            ld mid=(st+en)/2;
            vector<line>crr(n);
            vector<pair<LD,LD>>drr;
            for(i=0;i<n;i++){
                crr[i]=brr[i];
                crr[i].c+=sqrt((ld)(brr[i].a*brr[i].a+brr[i].b*brr[i].b))*mid;
            }
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i!=j&&abs(crr[i].a*crr[j].b-crr[i].b*crr[j].a)>eps){
                        drr.push_back({
                            -(1/(crr[i].a*crr[j].b-crr[i].b*crr[j].a))
                                      *(crr[j].b*crr[i].c-crr[i].b*crr[j].c),
                                (1/(crr[i].a*crr[j].b-crr[i].b*crr[j].a))
                                *(crr[j].a*crr[i].c-crr[i].a*crr[j].c)});
                    }
                }
            }
            for(j=0;j<drr.size();j++){
                for(i=0;i<n;i++){
                    if(crr[i].a*drr[j].first+crr[i].b*drr[j].second+crr[i].c<eps);
                    else break;
                }
                if(i==n)x++;
            }
            if(!x){
                en=mid;
            }
            else st=mid;
        }
        cout<<fixed<<setprecision(10)<<st<<'\n';
    }
}

int main() {
    setup();
    solve();
    return 0;
}
