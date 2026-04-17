#include<bits/stdc++.h>
using namespace std;
#ifdef ATCODER
//#include<atcoder/all>
//using namespace atcoder;
#endif
using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;
using pld = pair<ld,ld>;
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

void yes(){
    cout<<"Yes\n";
}

void no(){
    cout<<"No\n";
}

void preprocess(){

}

constexpr ll mod=998244353;

ll modpow(ll a,ll b){
    a%=mod;
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

ll modinv(ll a){
    return modpow(a,mod-2);
}
struct Point {
    ld x, y;
    Point operator+(const Point& rhs) const { return Point{x + rhs.x, y + rhs.y}; }
    Point operator-(const Point& rhs) const { return Point{x - rhs.x, y - rhs.y}; }
    Point operator*(ld t) const { return Point{x * t, y * t}; }
};
struct Line {
    Point pos, dir;
};
struct Circle {
    Point center;
    ld r;
};
inline ld inner(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline ld dist(const Point& a, const Point& b) { return sqrt(inner(a - b, a - b)); }
inline ld outer(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
const ld eps = 1e-12;
inline ll diff(ld lhs, ld rhs) {
    if (lhs - eps < rhs && rhs < lhs + eps) return 0;
    return (lhs < rhs) ? -1 : 1;
}
bool get_cross(const Line& a, const Line& b, Point& ret) {
    ld mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    ld t2 = outer(a.dir, b.pos - a.pos) / mdet;
    ret = b.pos + b.dir * t2;
    return true;
}
Circle circle_from_3pts(const Point& a, const Point& b, const Point& c) {
    Point ba = b - a, cb = c - b;
    Line p{(a + b) * 0.5, Point{ba.y, -ba.x}};
    Line q{(b + c) * 0.5, Point{cb.y, -cb.x}};
    Circle circle;
    if (!get_cross(p, q, circle.center))
        circle.r = -1;
    else
        circle.r = dist(circle.center, a);
    return circle;
}
Circle circle_from_2pts(const Point& a, const Point& b) {
    Circle circle;
    circle.center = (a + b) * 0.5;
    circle.r = dist(a, b) / 2;
    return circle;
}
Circle minimumEnclosingCost(vector<Point> v){
    // O(n^3) but if random_shuffle is used, it is amortized O(n)
    random_shuffle(v.begin(), v.end());
    Point p = {0, 0};
    ld r = 0; int n = v.size();
    for(int i=0; i<n; i++) if(dist(p, v[i]) > r){
            p = v[i]; r = 0;
            for(int j=0; j<i; j++) if(dist(p, v[j]) > r){
                    auto tmp=circle_from_2pts(v[i], v[j]);
                    p = tmp.center; r = tmp.r;
                    for(int k=0; k<j; k++) if(dist(p, v[k]) > r){
                            auto tmp=circle_from_3pts(v[i], v[j], v[k]);
                            p = tmp.center; r = tmp.r;
                        }
                }
        }
    return {p, r};
}
void solve(){
    ll i,j;
    ll n;
    cin>>n;
    vector<Point> v(n);
    for(i=0;i<n;i++){
        cin>>v[i].x>>v[i].y;
    }
    auto [p,r]=minimumEnclosingCost(v);
    cout<<fixed<<setprecision(2)<<r*2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
#ifdef kidw0124
    clock_t st=clock();
#endif
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}