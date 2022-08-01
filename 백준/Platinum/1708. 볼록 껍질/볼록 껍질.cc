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

ll ccw(pll a, pll b, pll c){
    return (c.second-a.second)*(b.first-a.first)-(b.second-a.second)*(c.first-a.first);
}
bool up(pll a, pll b, pll c){
    return ccw(a,b,c)>=0;
}

vector<pll>convexhull(vector<pll>&points){
    vector<pll>ret;
    sort(all(points));
    vector<pll>l,h;
    for(ll i=0;i<points.size();i++){
        while(l.size()>=2&&ccw(*(l.rbegin()+1),*l.rbegin(),points[i])<=0)l.pop_back();
        while(h.size()>=2&&ccw(*(h.rbegin()+1),*h.rbegin(),points[i])>=0)h.pop_back();
        l.push_back(points[i]);
        h.push_back(points[i]);
    }
    h.pop_back();
    reverse(all(h));
    h.pop_back();
    each(x,l)ret.push_back(x);
    each(x,h)ret.push_back(x);
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>arr(n);
    for(i=0;i<n;i++)cin>>arr[i].first>>arr[i].second;
    cout<<convexhull(arr).size();

    return 0;
}
