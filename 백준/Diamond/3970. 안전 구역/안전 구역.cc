#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 998244353;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

bool is_in_area(pair<ll, ll> p1, pair<ll, ll> p2, ll radius) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) <= radius * radius;
}

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

const ld eps=1e-12;
inline ll diff(ld lhs, ld rhs) {
    if(lhs - eps < rhs && rhs < lhs + eps)return 0;
    return (lhs < rhs) ? -1 : 1;
}

inline bool is_between(ld check, ld a, ld b) {
    return (a < b) ? (a - eps < check && check < b + eps) : (b - eps < check && check < a + eps);
}

struct Point {
    ld x, y;
    ll idx;
    bool operator==(const Point& rhs) const {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    Point operator+(const Point& rhs) const {
        return Point{x + rhs.x, y + rhs.y};
    }
    Point operator-(const Point& rhs) const {
        return Point{x - rhs.x, y - rhs.y};
    }
    Point operator*(ld t) const {
        return Point{x * t, y * t};
    }
};

using Matrix = vector<vector<ld>>;

struct Circle {
    Point center;
    ld r;
};

struct Line {
    Point pos, dir;
};

inline ld inner(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

inline ld outer(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

inline ll ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point - line.pos), 0);
}

inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b - a, c - a), 0);
}

inline ld dist(const Point& a, const Point& b) {
    return sqrt(inner(a - b, a - b));
}

inline ld dist2(const Point& a, const Point& b) {
    return inner(a - b, a - b);
}

inline ld dist(const Line& line, const Point& point, bool segment = false) {
    ld c1 = inner(point - line.pos, line.dir);
    if(segment && diff(c1, 0) <= 0)return dist(line.pos, point);
    ld c2 = inner(line.dir, line.dir);
    if(segment && diff(c2, c1) <= 0)return dist(line.pos + line.dir, point);
    return dist(line.pos + line.dir * (c1 / c2), point);
}

vector<Point> convex_hull(vector<Point> dat) {
    if(dat.size() <= 3)return dat;
    vector<Point> upper, lower;
    sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });
    for(const auto& p : dat) {
        while(upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0)upper.pop_back();
        while(lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0)lower.pop_back();
        upper.emplace_back(p);
        lower.emplace_back(p);
    }
    upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
    return upper;
}

Point operator*(const Matrix&m,const Point&r){
    Point ret = r;
    ret.x=r.x*m[0][0]+r.y*m[0][1];
    ret.y=r.x*m[1][0]+r.y*m[1][1];
    return ret;
}

vector<Point>points;

void func(Circle a, Circle b){
    if(a.r>b.r){
        swap(a,b);
    }
    ld ox=a.center.x,oy=a.center.y;
    a.center.x-=ox,a.center.y-=oy;
    b.center.x-=ox,b.center.y-=oy;
    bool inv;
    if(b.center.x<0)inv=true;
    else inv=false;
    if(inv){
        b.center.x*=-1;
    }
    ld d = sqrt(inner(b.center,b.center));
    Matrix itransform = {
            {b.center.x/d,-b.center.y/d},
            {b.center.y/d,b.center.x/d},
        };
    Matrix transform = {
            {b.center.x/d,b.center.y/d},
            {-b.center.y/d,b.center.x/d},
        };
    Point t1,t2,t3,t4;
    t1.idx=a.center.idx;
    t2.idx=a.center.idx;
    t3.idx=b.center.idx;
    t4.idx=b.center.idx;
    b.center=transform*b.center;
    d=dist(a.center,b.center);
    ld l = sqrt(d*d-(b.r-a.r)*(b.r-a.r));
    ld ctheta,stheta;
    if(diff(a.r,b.r)) {
        ld p = a.r * l / (b.r - a.r);
        ld q = d * a.r / (b.r - a.r);
        ctheta = p / q;
        stheta = sqrt(1 - p * p / (q * q));
    }
    else{
        stheta=0;
        ctheta=1;
    }
    t1.x=-a.r*stheta;
    t1.y=a.r*ctheta;
    t2.x=-a.r*stheta;
    t2.y=-a.r*ctheta;
    t3.x=-b.r*stheta+b.center.x;
    t3.y=b.r*ctheta;
    t4.x=-b.r*stheta+b.center.x;
    t4.y=-b.r*ctheta;

    t1=itransform*t1;
    t2=itransform*t2;
    t3=itransform*t3;
    t4=itransform*t4;

    if(inv){
        t1.x*=-1;
        t2.x*=-1;
        t3.x*=-1;
        t4.x*=-1;
    }
    t1.x+=ox,t1.y+=oy;
    t2.x+=ox,t2.y+=oy;
    t3.x+=ox,t3.y+=oy;
    t4.x+=ox,t4.y+=oy;
    points.push_back(t1);
    points.push_back(t2);
    points.push_back(t3);
    points.push_back(t4);
}

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<Circle>arr(n);
    points.clear();
    for(i=0;i<n;i++){
        cin>>arr[i].center.x>>arr[i].center.y>>arr[i].r;
        arr[i].center.idx=i;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            func(arr[i],arr[j]);
        }
    }
    if(n==1){
        cout<<fixed<<setprecision(10)<<2* acos((ld)-1)*arr[0].r<<'\n';
        return;
    }
//    for(auto k:points){
//        cout<<k.x<<' '<<k.y<<' '<<k.idx<<'\n';
//    }
//    cout<<'\n';
    vector<Point> ch = convex_hull(points);
//    for(auto k:ch){
//        cout<<k.x<<' '<<k.y<<' '<<k.idx<<'\n';
//    }
//    cout<<'\n';
    ld ans=0;
    n=ch.size();
    for(i=0;i<n;i++){
        Point now = ch[i],now1 = ch[(i+1)%n];
        if(now.idx!=now1.idx){
            ans+=dist(now,now1);
        }
        else{
            ld cs = inner(now-arr[now.idx].center,now1-arr[now.idx].center)
                    / (dist(now,arr[now.idx].center)
                        *dist(now1,arr[now.idx].center));
            ld theta = acos(cs);
            if(ccw(now,arr[now.idx].center,now1)>0){
                ans+=arr[now.idx].r*theta;
            }
            else{
                ans+=arr[now.idx].r*(2*acos((ld)-1)-theta);
            }
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}

int main(){
    setup();
    ll t=1,tc;
    cin >> t;
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}

