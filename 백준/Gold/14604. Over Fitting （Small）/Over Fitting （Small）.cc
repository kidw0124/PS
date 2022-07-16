#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

bool up(pll a, pll b, pll c){
    return (b.second-a.second)*(c.first-a.first)+a.second*(b.first-a.first)<=c.second*(b.first-a.first);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>black,white;
    for(i=0;i<n;i++){
        ll x,y;
        string str;
        cin>>x>>y>>str;
        if(str=="LOVELYZ")white.push_back({x,y});
        else black.push_back({x,y});
    }
    ll b=black.size(),w=white.size();
    ll ans=0;
    for(i=0;i<b;i++){
        for(j=0;j<w;j++){
            ll ww=0,bb=0;
            for(ll k=0;k<b;k++){
                if(k!=i)bb+=up(black[i],white[j],black[k]);
            }
            if(0<bb&&bb<b-1)continue;
            for(ll k=0;k<w;k++){
                if(k!=j)ww+=up(black[i],white[j],white[k]);
            }
            if(bb){
                ans=max(w-ww,ans);
            }
            else ans=max(ww,ans);
        }
    }
    cout<<ans;
    return 0;
}
