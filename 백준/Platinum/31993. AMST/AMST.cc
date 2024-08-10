#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

const ll mod = 1e9+7;

void setup()
{
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

ll powm(ll a, ll b, ll m = mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void preprocess() {
    ll i, j;


}

const ld PI_2 = acos((ld)0);
const ld eps = 1e-8;

struct edges{
    ll u,v,a,b;
    ll idx;
    ld w(ld x)const{
        return a*x+b;
    }
    bool operator<(const edges &e) const{
        return idx < e.idx;
    }
};
vector<ll>grp;

ll find(ll x){
    return grp[x] == x ? x : grp[x] = find(grp[x]);
}

void merge(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x != y){
        grp[x] = y;
    }
}

ld mst(ld x, ll n, vector<edges> &e){
    grp.clear();
    grp.resize(n);
    iota(all(grp),0);
    ld ret = 0;
    ll cnt = 0;
    priority_queue<pair<ld,edges>>pq;
    for(auto &i : e){
        pq.push({-i.w(x),i});
    }
    while(cnt < n-1){
        auto [w,p] = pq.top();
        auto [u,v,a,b,idx] = p;
        pq.pop();
        if(find(u) != find(v)){
            merge(u,v);
            cnt++;
            ret += a*x+b;
        }
    }
    return ret;
}

void solve(ll testcase){
    ll i,j;
    ll n,m,s;
    cin >> n >> m;
    vector<edges> e(m);
    for(i=0;i<m;i++){
        cin >> e[i].u >> e[i].v >> e[i].a >> e[i].b;
        e[i].u--, e[i].v--;
        e[i].idx = i;
    }
    cin>>s;
    sort(all(e),[](const edges &a, const edges &b){
        return a.a < b.a;
    });
    ll mini = 0, maxi = 0;
    vector<ll> grp1(n),grp2(n);
    iota(all(grp1),0), iota(all(grp2),0);
    function<ll(ll, vector<ll>&)> find_grp = [&](ll x, vector<ll> &grp){
        return grp[x] == x ? x : grp[x] = find_grp(grp[x],grp);
    };
    function<void(ll,ll,vector<ll>&)> merge_grp = [&](ll x, ll y, vector<ll> &grp){
        x = find_grp(x,grp);
        y = find_grp(y,grp);
        if(x != y){
            grp[x] = y;
        }
    };
    for(i=0;i<m;i++){
        auto [u,v,a,b,idx] = e[i];
        if(find_grp(u,grp1) != find_grp(v,grp1)){
            merge_grp(u,v,grp1);
            mini += a;
        }
    }
    for(i=m-1;i>=0;i--){
        auto [u,v,a,b,idx] = e[i];
        if(find_grp(u,grp2) != find_grp(v,grp2)){
            merge_grp(u,v,grp2);
            maxi += a;
        }
    }
    if(mini>0){
        ld st=-2e12, en=2e12;
        while(en-st > eps){
            ld mid = (st+en)/2;
            if(mst(mid,n,e) < s){
                st = mid;
            }
            else{
                en = mid;
            }
        }
        cout<<"YES\n";
        cout<<fixed<<setprecision(12)<<st<<'\n';


    }
    else if(maxi < 0){
        ld st=-2e12, en=2e12;
        while(en-st > eps){
            ld mid = (st+en)/2;
            if(mst(mid,n,e) > s){
                st = mid;
            }
            else{
                en = mid;
            }
        }
        cout<<"YES\n";
        cout<<fixed<<setprecision(12)<<st<<'\n';
    }
    else {
        ld st = -1000, en = 1000;
        while (en - st > 1e-6) {
            ld mid1 = (st * 2 + en) / 3;
            ld mid2 = (st + en * 2) / 3;
            if (mst(mid1, n, e) > mst(mid2, n, e)) {
                en = mid2;
            } else {
                st = mid1;
            }
        }
        ld val = mst(st, n, e);
        if(val <s){
            cout<<"NO\n";
        }
        else{
            ld st1=val,en1=2e12;
            while(en1-st1 > eps){
                ld mid = (st1+en1)/2;
                if(mst(mid,n,e) > s){
                    st1 = mid;
                }
                else{
                    en1 = mid;
                }
            }
            cout<<"YES\n";
            cout<<fixed<<setprecision(12)<<st1<<'\n';
        }
    }


}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++)
    {
        solve(testcase);
    }
    return 0;
}
