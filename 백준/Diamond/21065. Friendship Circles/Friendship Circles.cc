#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
typedef unsigned long long ull;
typedef __float128 LD;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
#define debugv(x) if constexpr(ddebug){cout<<"[DEBUG] "<<#x<<" : "<<x<<'\n';}
#define debugc(c) if constexpr(ddebug) {cout << "[DEBUG] "<<#c<<" : "; for(auto &x : c) cout << x << ", "; cout << '\n';}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b)
{
    if (a && b)
        return a * (b / gcd(a, b));
    return a + b;
}
ll powm(ll a, ll b, ll rem)
{
    ll p = 1;
    for (; b; b /= 2, a = (a * a) % rem)
        if (b & 1)
            p = (p * a) % rem;
    return p;
}
pair<ll, ll> extended_gcd(ll a, ll b)
{
    if (b == 0)
        return {1, 0};
    auto t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}
ll modinverse(ll a, ll m)
{
    return (extended_gcd(a, m).first % m + m) % m;
}

ll large_mod_mul(ll a, ll b, ll m)
{
    return ll((__int128)a * (__int128)b % m);
}
ll modpow(ll n, ll k, ll m)
{
    ll ret = 1;
    n %= m;
    while (k)
    {
        if (k & 1)
            ret = large_mod_mul(ret, n, m);
        n = large_mod_mul(n, n, m);
        k /= 2;
    }
    return ret;
}
bool test_witness(ull a, ull n, ull s)
{
    if (a >= n)
        a %= n;
    if (a <= 1)
        return true;
    ull d = n >> s;
    ull x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (s-- > 1)
    {
        x = large_mod_mul(x, x, n);
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}
bool is_prime(ull n)
{
    if (n == 2)
        return true;
    if (n < 2 || n % 2 == 0)
        return false;
    ull d = n >> 1, s = 1;
    for (; (d & 1) == 0; s++)
        d >>= 1;
#define T(a) test_witness(a##ull, n, s)
    if (n < 4759123141ull)
        return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178) && T(450775) && T(9780504) && T(1795265022);
#undef T
}
ll pollard_rho(ll n)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(1, n - 1);
    ll x = dis(gen);
    ll y = x;
    ll c = dis(gen);
    ll g = 1;
    while (g == 1)
    {
        x = (large_mod_mul(x, x, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        y = (large_mod_mul(y, y, n) + c) % n;
        g = gcd(abs(x - y), n);
    }
    return g;
}
void factorize(ll n, map<ll, ll> &fl)
{
    if (n == 1)
    {
        return;
    }
    if (n % 2 == 0)
    {
        fl[2]++;
        factorize(n / 2, fl);
    }
    else if (is_prime(n))
    {
        fl[n]++;
    }
    else
    {
        ll f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

struct segment
{
    vector<ll> segtree, prop, dat;
    segment(ll n)
    {
        segtree.resize(TSIZE * 2);
        prop.resize(TSIZE * 2);
        dat.resize(n);
    }
    void seg_init(ll nod, ll l, ll r)
    {
        if (l == r)
            segtree[nod] = dat[l];
        else
        {
            ll m = (l + r) >> 1;
            seg_init(nod << 1, l, m);
            seg_init(nod << 1 | 1, m + 1, r);
            segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
        }
    }

    void seg_relax(ll nod, ll l, ll r)
    {
        if (prop[nod] == 0)
            return;
        if (l < r)
        {
            ll m = (l + r) >> 1;
            segtree[nod << 1] += (m - l + 1) * prop[nod];
            prop[nod << 1] += prop[nod];
            segtree[nod << 1 | 1] += (r - m) * prop[nod];
            prop[nod << 1 | 1] += prop[nod];
        }
        prop[nod] = 0;
    }

    ll seg_query(ll nod, ll l, ll r, ll s, ll e)
    {
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return segtree[nod];
        seg_relax(nod, l, r);
        ll m = (l + r) >> 1;
        return seg_query(nod << 1, l, m, s, e) + seg_query(nod << 1 | 1, m + 1, r, s, e);
    }

    void seg_update(ll nod, ll l, ll r, ll s, ll e, ll val)
    {
        if (r < s || e < l)
            return;
        if (s <= l && r <= e)
        {
            segtree[nod] += (r - l + 1) * val;
            prop[nod] += val;
            return;
        }
        seg_relax(nod, l, r);
        ll m = (l + r) >> 1;
        seg_update(nod << 1, l, m, s, e, val);
        seg_update(nod << 1 | 1, m + 1, r, s, e, val);
        segtree[nod] = segtree[nod << 1] + segtree[nod << 1 | 1];
    }
    // usage:
    // seg_update(1, 0, n - 1, qs, qe, val);
    // seg_query(1, 0, n - 1, qs, qe);
};

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
}

#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef pair<ld, ld> pdd;

const ld EPS = 1e-9;
int dcmp(ld x){ return x < -EPS? -1 : x > EPS ? 1 : 0; }

ld operator / (pdd a,    pdd b){ return a.first * b.second - a.second * b.first; }
pdd    operator * (ld b, pdd a){ return pdd(b * a.first, b * a.second); }
pdd    operator + (pdd a,    pdd b){ return pdd(a.first + b.first, a.second + b.second); }
pdd    operator - (pdd a,    pdd b){ return pdd(a.first - b.first, a.second - b.second); }

ld sq(ld x){ return x*x; }
ld size(pdd p){ return hypot(p.first, p.second); }
ld sz2(pdd p){ return sq(p.first) + sq(p.second); }
pdd r90(pdd p){ return pdd(-p.second, p.first); }

pdd line_intersect(pdd a, pdd b, pdd u, pdd v){ return u + (((a-u)/b) / (v/b))*v; }
pdd get_circumcenter(pdd p0, pdd p1, pdd p2){
    return line_intersect(0.5 * (p0+p1), r90(p0-p1), 0.5 * (p1+p2), r90(p1-p2));
}

// https://www.youtube.com/watch?v=h_vvP4ah6Ck
ld parabola_intersect(pdd left, pdd right, ld sweepline){
    /*
    if(dcmp(left.second - right.second) == 0) return (left.first + right.first) / 2.0; /*/
    auto f2 = [](pdd left, pdd right, ld sweepline){
        int sign = left.first < right.first ? 1 : -1;
        pdd m = 0.5 * (left+right);
        pdd v = line_intersect(m, r90(right-left), pdd(0, sweepline), pdd(1, 0));
        pdd w = line_intersect(m, r90(left-v), v, left-v);
        ld l1 = size(v-w), l2 = sqrt(sq(sweepline-m.second) - sz2(m-w)), l3 = size(left-v);
        return v.first + (m.first - v.first) * l3 / (l1 + sign * l2);
    };
    if(abs(left.second - right.second) < abs(left.first - right.first) * EPS) return f2(left, right, sweepline);// */
    int sign = left.second < right.second ? -1 : 1;
    pdd v = line_intersect(left, right-left, pdd(0, sweepline), pdd(1, 0));
    ld d1 = sz2(0.5 * (left+right) - v), d2 = sz2(0.5 * (left-right));
    return v.first + sign * sqrt(max((ld)0.0, d1 - d2));
}

class Beachline{
public:
    struct node{
        node(){}
        node(pdd point, int idx):point(point), idx(idx), end(0),
                                 link{0, 0}, par(0), prv(0), nxt(0) {}
        pdd point; int idx; int end;
        node *link[2], *par, *prv, *nxt;
    };
    node *root;
    ld sweepline;

    Beachline() : sweepline(-1e20), root(NULL){ }
    inline int dir(node *x){ return x->par->link[0] != x; }

    //     p        n          p            n
    //    / \      / \        / \          / \
		//   n   d => a   p   or a   n   =>   p   d
    //  / \          / \        / \      / \
		// a   b        b   d      c   d    a   c

    void rotate(node *n){
        node *p = n->par;         int d = dir(n);
        p->link[d] = n->link[!d]; if(n->link[!d]) n->link[!d]->par = p;
        n->par = p->par;          if(p->par) p->par->link[dir(p)] = n;
        n->link[!d] = p;          p->par = n;
    }

    void splay(node *x, node *f = NULL){
        while(x->par != f){
            if(x->par->par == f);
            else if(dir(x) == dir(x->par)) rotate(x->par);
            else rotate(x);
            rotate(x);
        }
        if(f == NULL) root = x;
    }

    void insert(node *n, node *p, int d){
        splay(p); node* c = p->link[d];
        n->link[d] = c; if(c) c->par = n;
        p->link[d] = n; n->par = p;

        node *prv = !d?p->prv:p, *nxt = !d?p:p->nxt;
        n->prv = prv;   if(prv) prv->nxt = n;
        n->nxt = nxt;   if(nxt) nxt->prv = n;
    }

    void erase(node* n){
        node *prv = n->prv, *nxt = n->nxt;
        if(!prv && !nxt){ if(n == root) root = NULL; return; }
        n->prv = NULL;   if(prv) prv->nxt = nxt;
        n->nxt = NULL;   if(nxt) nxt->prv = prv;
        splay(n);
        if(!nxt){
            root->par = NULL; n->link[0] = NULL;
            root = prv;
        }
        else{
            splay(nxt, n);     node* c = n->link[0];
            nxt->link[0] = c;  c->par = nxt;         n->link[0] = NULL;
            n->link[1] = NULL; nxt->par = NULL;
            root = nxt;
        }
    }
    bool get_event(node* cur, ld &next_sweep){
        if(!cur->prv || !cur->nxt) return false;
        pdd u = r90(cur->point - cur->prv->point);
        pdd v = r90(cur->nxt->point - cur->point);
        if(dcmp(u/v) != 1) return false;
        pdd p = get_circumcenter(cur->point, cur->prv->point, cur->nxt->point);
        next_sweep = p.second + size(p - cur->point);
        return true;
    }
    node* find_beachline(ld x){
        node* cur = root;
        while(cur){
            ld left = cur->prv ? parabola_intersect(cur->prv->point, cur->point, sweepline) : -1e30;
            ld right = cur->nxt ? parabola_intersect(cur->point, cur->nxt->point, sweepline) : 1e30;
            if(left <= x && x <= right){ splay(cur); return cur; }
            cur = cur->link[x > right];
        }
    }
}; using BeachNode = Beachline::node;

static BeachNode* arr;
static int sz;
static BeachNode* new_node(pdd point, int idx){
    arr[sz] = BeachNode(point, idx);
    return arr + (sz++);
}

struct event{
    event(ld sweep, int idx):type(0), sweep(sweep), idx(idx){}
    event(ld sweep, BeachNode* cur):type(1), sweep(sweep), prv(cur->prv->idx), cur(cur), nxt(cur->nxt->idx){}
    int type, idx, prv, nxt;
    BeachNode* cur;
    ld sweep;
    bool operator>(const event &l)const{ return sweep > l.sweep; }
};

void VoronoiDiagram(vector<pdd> &input, vector<pdd> &vertex, vector<pii> &edge, vector<pii> &area){
    Beachline beachline = Beachline();
    priority_queue<event, vector<event>, greater<event>> events;

    auto add_edge = [&](int u, int v, int a, int b, BeachNode* c1, BeachNode* c2){
        if(c1) c1->end = edge.size()*2;
        if(c2) c2->end = edge.size()*2 + 1;
        edge.emplace_back(u, v);
        area.emplace_back(a, b);
    };
    auto write_edge = [&](int idx, int v){ idx%2 == 0 ? edge[idx/2].first = v : edge[idx/2].second = v; };
    auto add_event = [&](BeachNode* cur){ ld nxt; if(beachline.get_event(cur, nxt)) events.emplace(nxt, cur); };

    int n = input.size(), cnt = 0;
    arr = new BeachNode[n*4]; sz = 0;
    sort(input.begin(), input.end(), [](const pdd &l, const pdd &r){
        return l.second != r.second ? l.second < r.second : l.first < r.first;
    });

    BeachNode* tmp = beachline.root = new_node(input[0], 0), *t2;
    for(int i = 1; i < n; i++){
        if(dcmp(input[i].second - input[0].second) == 0){
            add_edge(-1, -1, i-1, i, 0, tmp);
            beachline.insert(t2 = new_node(input[i], i), tmp, 1);
            tmp = t2;
        }
        else events.emplace(input[i].second, i);
    }
    while(events.size()){
        event q = events.top(); events.pop();
        BeachNode *prv, *cur, *nxt, *site;
        int v = vertex.size(), idx = q.idx;
        beachline.sweepline = q.sweep;
        if(q.type == 0){
            pdd point = input[idx];
            cur = beachline.find_beachline(point.first);
            beachline.insert(site = new_node(point, idx), cur, 0);
            beachline.insert(prv = new_node(cur->point, cur->idx), site, 0);
            add_edge(-1, -1, cur->idx, idx, site, prv);
            add_event(prv); add_event(cur);
        }
        else{
            cur = q.cur, prv = cur->prv, nxt = cur->nxt;
            if(!prv || !nxt || prv->idx != q.prv || nxt->idx != q.nxt) continue;
            vertex.push_back(get_circumcenter(prv->point, nxt->point, cur->point));
            write_edge(prv->end, v); write_edge(cur->end, v);
            add_edge(v, -1, prv->idx, nxt->idx, 0, prv);
            beachline.erase(cur);
            add_event(prv); add_event(nxt);
        }
    }
    delete arr;
}

const ll mod = 1e9+7;
void preprocess() {

}
void solve(ll testcase) {
    ll i,j;
    ll n,m;
    string str;
    cin>>n;
    vector<pdd> p(n),ver;
    vector<pii>edg,are;
    map<pdd,vector<ll>>rev;

    for(i=0;i<n;i++) {
        cin>>p[i].first>>p[i].second;
        // rotate 1 rad
        pdd tmp = p[i];
        p[i].first = tmp.first*cosl(1)-tmp.second*sinl(1);
        p[i].second = tmp.first*sinl(1)+tmp.second*cosl(1);
        rev[p[i]].push_back(i);
    }
    VoronoiDiagram(p,ver,edg,are);
//    vector<ll>ans(n,LONG_LONG_MAX);
//    for(auto &[a,b]:rev){
//        if(b.size()>1){
//            for(auto k:b){
//                ans[k]=0;
//            }
//        }
//    }
    set<ll>ans;
    for(auto &k:are){
        ll a=k.first,b=k.second;
        if(rev[p[a]][0]==0)ans.insert(rev[p[b]][0]);
        if(rev[p[b]][0]==0)ans.insert(rev[p[a]][0]);
//        pdd di=p[b]-p[a];
//        ans[rev[p[a]][0]]=min(ans[rev[p[a]][0]],(ll)(di.first*di.first+di.second*di.second+1e-9));
//        ans[rev[p[b]][0]]=min(ans[rev[p[b]][0]],(ll)(di.first*di.first+di.second*di.second+1e-9));
    }
    cout<<ans.size()<<' ';
    for(auto &e  : ans) {
        cout<<e<<' ';
    }
    cout<<'\n';


}

int main() {
    setup();
    preprocess();
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}