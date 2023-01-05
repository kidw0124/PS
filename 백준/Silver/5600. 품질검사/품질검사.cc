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

struct toy{
    ll a,b,c;
    ll r;
    bool operator<(const toy&r)const{
        return r.r<this->r;
    }
};

int main() {
    setup();
    ll i, j;
    ll n,a,b,c;
    cin>>a>>b>>c>>n;
    vector<ll>arr(a+b+c+1,2);
    vector<toy>brr(n);
    for(i=0;i<n;i++){
        cin>>brr[i].a>>brr[i].b>>brr[i].c>>brr[i].r;
    }
    sort(all(brr));
    ll cnt= std::count_if(brr.begin(), brr.end(),[](toy a){
        return a.r==1;
    });
    for(i=0;i<cnt;i++){
        arr[brr[i].a]=arr[brr[i].b]=arr[brr[i].c]=1;
    }
    for(i=cnt;i<n;i++){
        if(arr[brr[i].a]==1&&arr[brr[i].b]==1&&brr[i].r==0)arr[brr[i].c]=0;
        if(arr[brr[i].a]==1&&arr[brr[i].c]==1&&brr[i].r==0)arr[brr[i].b]=0;
        if(arr[brr[i].c]==1&&arr[brr[i].b]==1&&brr[i].r==0)arr[brr[i].a]=0;
    }
    for(i=1;i<=a+b+c;i++)cout<<arr[i]<<' ';
}