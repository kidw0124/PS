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

vector<pll>dif({
              {0,1},{1,1},{1,0},{1,-1},
              {0,-1},{-1,-1},{-1,0},{-1,1}
              });

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n;
    set<pll>pt;
    cin>>n;
    ll x=0,y=0;
    pt.insert({x,y});
    set<set<pll>>edge;
    for(i=0;i<n;i++){
        char c;
        cin>>c;
        c-='0';
        pt.insert({x+dif[c].first,y+dif[c].second});
        set<pll>st;
        st.insert({x,y});
        st.insert({x+dif[c].first,y+dif[c].second});
        edge.insert(st);
        x+=dif[c].first;
        y+=dif[c].second;
        pt.insert({x+dif[c].first,y+dif[c].second});
        st.clear();
        st.insert({x,y});
        st.insert({x+dif[c].first,y+dif[c].second});
        edge.insert(st);
        x+=dif[c].first;
        y+=dif[c].second;
    }
    cout<<1-pt.size()+edge.size();
    return 0;
}
