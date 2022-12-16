#include<bits/stdc++.h>
using namespace std;
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
    ll n;
    cin>>n;
    vector<tuple<ll,bool,ll>>arr;
    map<pair<ll,ll>,ll>las;
    priority_queue<pair<ll,ll>>pq;
    set<ll>term;
    for(i=0;i<n;i++){
        ll l,r,h;
        cin>>l>>h>>r;
        arr.push_back({l,0,-h});
        arr.push_back({r,1,-h});
        las[{l,h}]=r;
    }
    sort(all(arr));
    ll ans=0;
    for(i=0;i<2*n;i++){
        auto [pos,x,h]=arr[i];
//        debug<<pos<<' '<<x<<' '<<h<<'\n';
        if(x){
            term.insert(pos);
            while(!pq.empty()&&term.find(pq.top().second)!=term.end())pq.pop();
            if(pq.empty()){
                if(ans){
                    ans=0;
                    cout<<pos<<' '<<0<<' ';
                }
            }
            else{
                if(pq.top().first!=ans){
                    ans=pq.top().first;
                    cout<<pos<<' '<<ans<<' ';
                }
            }
        }
        else{
            if(ans<-h){
                ans=-h;
                cout<<pos<<' '<<ans<<' ';
            }
            pq.push({-h,las[{pos,-h}]});
        }
    }


    return 0;
}
