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

pair<ll, ll> extended_gcd(ll a, ll b) {
    if (b == 0) return { 1, 0 };
    auto t = extended_gcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}
ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

map<ll,ll>factorize(ll x){
    map<ll,ll>ret;
    ll xp=x;
    for(ll i=2;i*i<=x;i++){
        while(xp%i==0){
            ret[i]++;
            xp/=i;
        }
    }
    if(xp>1)ret[xp]++;
    return ret;
}

int main() {
    setup();
    ll i,j;
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n+1),ans(n+1);
    map<ll,vector<ll>>cyc;
    map<ll,vector<vector<ll>>>len_cyc;
    map<ll,ll>factor;
    vector<bool>chk(n+1);
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(i=1;i<=n;i++){
        if(chk[i])continue;
        ll now=i;
        do{
            cyc[i].push_back(now);
            now=arr[now];
            chk[now]=1;
        } while (now!=i);
        len_cyc[cyc[i].size()].push_back(cyc[i]);
    }
    factor = factorize(k);
    for(auto& [len,p]:len_cyc){
        ll groups=1;
        for(auto [pr,_] : factorize(len)){
            if(k%pr==0){
                groups *= powm(pr,factor[pr],LLONG_MAX);
            }
        }
        debug<<len<<' '<<groups<<'\n';
        if(p.size()%groups!=0){
            cout<<"Impossible\n";
            return 0;
        }
        else{
            for(i=0;i<p.size();i+=groups){
                vector<ll>tmp;
                for(j=0;j<len;j++){
                    for(ll t=0;t<groups;t++){
                        tmp.push_back(p[i+t][j]);
                    }
                }
                ll inv = modinverse(k/groups,len);
                for(j=0;j<tmp.size();j++){
                    ans[tmp[j]]=tmp[(j+inv)%tmp.size()];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}