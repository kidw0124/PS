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
    return ccw(a,b,c)>0;
}

bool isc(pll a, pll b, pll c, pll d){
    return !up(a,b,d)||!up(b,c,d);
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
    vector<pll>black,white;
    for(i=0;i<n;i++){
        ll x,y;
        string str;
        cin>>x>>y>>str;
        if(str=="LOVELYZ")white.push_back({x,y});
        else black.push_back({x,y});
    }
    black=convexhull(black);
//    for(auto k:black){
//        cout<<k.first<<' '<<k.second<<'\n';
//    }
    ll w=white.size(),b=black.size();
    ll ans=0;
    for(i=0;i<b;i++){
        pll nex=black[(i+1)%b];
        sort(all(white),[&](auto l,auto r){
                return (up(nex,black[i],l)^up(nex,black[i],r))?up(nex,black[i],l):up(nex,l,r);
            });
//        cout<<white[0].first<<' '<<white[0].second<<'\n';
        ll ww=0,bb=0,j=0;
        ll l=0,r=0;
        ll now=0;
        pll nnex=black[(i+2)%b];
        if(isc(black[i],nex,nnex,white[0]))now++;
        while(l<w){
            if(r<l)r=l;
            while((r+1)<w&&up(nex,white[l],white[r+1])){
                r++;
                if(isc(black[i],nex,nnex,white[r])){
                    now++;
                    if(isc(black[i],nex,nnex,white[l]))ans=max(ans,now);
                }
            }
            if(isc(black[i],nex,nnex,white[r])&&isc(black[i],nex,nnex,white[l]))ans=max(ans,now);
            if(isc(black[i],nex,nnex,white[l]))now--;
            l++;
        }
    }
    cout<<ans;

    return 0;
}
