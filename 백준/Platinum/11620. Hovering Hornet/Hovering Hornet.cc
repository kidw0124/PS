#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma gcc optimize("O3,unroll-loops")
#pragma gcc target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool DEBUG = true;
#else
constexpr bool DEBUG = false;
#endif
#define debug if(DEBUG)cout<<"[DEBUG "<<__LINE__<<"] : "
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;

constexpr ll MOD = 1e9+7;
constexpr ll MOD_2=500'000'004;
constexpr ll MOD_4=250'000'002;
constexpr ll MOD_8=125'000'001;

void preprocess(){

}

const ld eps = 1e-12;
inline ll diff(ld lhs, ld rhs) {
    if (lhs - eps < rhs && rhs < lhs + eps) return 0;
    return (lhs < rhs) ? -1 : 1;
}
inline bool is_between(ld check, ld a, ld b) {
    return (a < b) ? (a - eps < check && check < b + eps)
                   : (b - eps < check && check < a + eps);
}
struct Point {
    ld x, y;
    bool operator==(const Point& rhs) const {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    Point operator+(const Point& rhs) const { return Point{x + rhs.x, y + rhs.y}; }
    Point operator-(const Point& rhs) const { return Point{x - rhs.x, y - rhs.y}; }
    Point operator*(ld t) const { return Point{x * t, y * t}; }
};
struct Circle {
    Point center;
    ld r;
};
struct Line {
    Point pos, dir;
};
inline ld inner(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline ld outer(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
inline ll ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point - line.pos), 0);
}
inline ld dist2(const Point& a, const Point& b) { return inner(a - b, a - b); }
bool get_cross(const Line& a, const Line& b, Point& ret) {
    ld mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    ld t2 = outer(a.dir, b.pos - a.pos) / mdet;
    ret = b.pos + b.dir * t2;
    return true;
}

vector<Point> cut_polygon(const vector<Point>& polygon, Line line) {
    if (!polygon.size()) return polygon;
    typedef vector<Point>::const_iterator piter;
    piter la, lan, fi, fip, i, j;
    la = lan = fi = fip = polygon.end();
    i = polygon.end() - 1;
    bool lastin = diff(ccw_line(line, polygon[polygon.size() - 1]), 0) > 0;
    for (j = polygon.begin() ; j != polygon.end() ; j++) {
        bool thisin = diff(ccw_line(line, *j), 0) > 0;
        if (lastin && !thisin) {
            la = i;
            lan = j;
        }
        if (!lastin && thisin) {
            fi = j;
            fip = i;
        }
        i = j;
        lastin = thisin;
    }
    if (fi == polygon.end()) {
        if (!lastin) return vector<Point>();
        return polygon;
    }
    vector<Point> result;
    for (i = fi ; i != lan ; i++) {
        if (i == polygon.end()) {
            i = polygon.begin();
            if (i == lan) break;
        }
        result.push_back(*i);
    }
    Point lc, fc;
    get_cross(Line{ *la, *lan - *la }, line, lc);
    get_cross(Line{ *fip, *fi - *fip }, line, fc);
    result.push_back(lc);
    if (diff(dist2(lc, fc), 0) != 0) result.push_back(fc);
    return result;
}

ld area(const vector<Point>& polygon) {
    ld ret = 0;
    for (int i = 0 ; i < polygon.size() ; i++) {
        int j = (i + 1) % polygon.size();
        ret += outer(polygon[i], polygon[j]);
    }
    return abs(ret) / 2;
}

void solve() {
    ll i,j,k;
    ld ans=500/(ld)124;
    vector<Point> poly(4);
    for(i=0;i<4;i++){
        cin>>poly[i].x>>poly[i].y;
    }
    Line line={{-0.5,0},{0,1}};
    vector<Point> res=cut_polygon(poly,line);
    ans+=area(res)*4*5/124;
    debug<<area(res)<<endl;
    line={{0.5,1},{0,-1}};
    res=cut_polygon(poly,line);
    ans+=area(res)*3*5/124;
    debug<<area(res)<<endl;
    line={{0,0.5},{1,0}};
    res=cut_polygon(poly,line);
    ans+=area(res)*6*5/124;
    debug<<area(res)<<endl;
    line={{0,-0.5},{-1,0}};
    res=cut_polygon(poly,line);
    ans+=area(res)*1*5/124;
    debug<<area(res)<<endl;
    cout<<fixed<<setprecision(10)<<ans;


}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
//    cin >> tc;
    while (tc--) solve();
}
