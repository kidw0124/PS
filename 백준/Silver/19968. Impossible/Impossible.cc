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

int main() {
    setup();
    ll i,j;
    ll a,b;
    cin>>a>>b;
    bitset<60*24>bs;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll x,y,z,w;
        char t;
        cin>>x>>t>>y>>t>>z>>t>>w;
        ll st=x*60+y,en=z*60+w;
        if(st<=en){
            for(j=st;j<=en;j++){
                bs[j]=1;
            }
        }
        else{
            for(j=st;j<60*24;j++){
                bs[j]=1;
            }
            for(j=0;j<=en;j++){
                bs[j]=1;
            }
        }
    }
    for(i=60*24-1;i>=0;i--){
        if(bs[i])break;
    }
    vector<pll>arr;
    pll tmp={-1,-1};
    ll st=i,en=bs._Find_first();
    ll d = 60 * 24 - 1 - st + en;
    if (d < a * 60) {
        for (i = st + 1; i < 60 * 24; i++) {
            bs[i] = 1;
        }
        for (i = 0; i < en; i++) {
            bs[i] = 1;
        }
    }
    while(st<60*24&&en<60*24){
        st=en;
        en=bs._Find_next(st);
        if(en==60*24){
            en=bs._Find_first()+60*24;
        }
        d=en-st-1;
        if(d<a*60){
            for(i=st;i<en;i++){
                bs[i]=1;
            }
        }
    }
    en=bs._Find_first();
    if(en>=bs.size()){
        cout<<"No\n";
        return 0;
    }
    auto bs2=bs;
    bs2.flip();
    st=0;
    while(st<60*24&&st<=en){
        st=bs2._Find_next(en);
        en=bs._Find_next(st);
        if(en<60*24)arr.push_back({st,en-1});
        else{
            en=bs._Find_first();
            if(en!=0||(bs[0]&&!bs[1439]))arr.push_back({st,(en+1439)%1440});
        }
    }
    if(arr.size()==0){
        cout<<"No\n";
        return 0;
    }
    for(i=0;i+1<arr.size();i++){
        ll d=arr[(i+1)%arr.size()].first-arr[i].second-1;
        if(d>b*60){
            cout<<"No\n";
            return 0;
        }
    }
    if(arr.back().first>arr.back().second){
        ll d=arr[(i+1)%arr.size()].first-arr[i].second-1;
        if(d>b*60){
            cout<<"No\n";
            return 0;
        }
    }
    else{
        ll d=arr[(i+1)%arr.size()].first+24*60-arr[i].second-1;
        if(d>b*60){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    cout<<arr.size()<<'\n';
    for(auto [f,s]:arr){
        cout<<setfill('0');
        cout<<setw(2)<<f/60%24<<":"<<setw(2)<<f%60<<"-"<<setw(2)<<s/60%24<<":"<<setw(2)<<s%60<<"\n";
    }
}