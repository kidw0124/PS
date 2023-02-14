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
    vector<vector<ll>>case1(100,vector<ll>(100)),case2(100,vector<ll>(100)),
                    ans1(100,vector<ll>(100)),ans2(100,vector<ll>(100));
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if((i+j)%3!=2){
                case1[i][j]=1;
            }
            if((i%3<2&&j%3<2)||(i%3==2&&j%3==2)){
                case2[i][j]=1;
            }
        }
    }
    ans1[0][0]=ans2[0][0]=1;
    for(i=1;i<100;i++){
        ans1[0][i]=ans1[0][i-1]+case1[0][i];
        ans2[0][i]=ans2[0][i-1]+case2[0][i];
        ans1[i][0]=ans1[i-1][0]+case1[i][0];
        ans2[i][0]=ans2[i-1][0]+case2[i][0];
    }
    for(i=1;i<100;i++){
        for(j=1;j<100;j++){
            ans1[i][j]=ans1[i-1][j]+ans1[i][j-1]-ans1[i-1][j-1]+case1[i][j];
            ans2[i][j]=ans2[i-1][j]+ans2[i][j-1]-ans2[i-1][j-1]+case2[i][j];
        }
    }
    ll t;
    cin>>t;
    for(i=0;i<t;i++){
        ll n,m;
        cin>>n>>m;
        cout<<"Case #"<<i+1<<": "<<max(ans1[n-1][m-1],ans2[n-1][m-1])<<'\n';
    }
}