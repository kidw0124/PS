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
struct Line {
    Point pos, dir;
};
inline ld inner(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline ld outer(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
inline ll ccw_line(const Line& line, const Point& point) {
    return diff(outer(line.dir, point - line.pos), 0);
}
inline ld dist2(const Point& a, const Point& b) { return inner(a - b, a - b); }
bool get_segment_cross(Line a, Line b) {
    ld mdet = outer(b.dir, a.dir);
    if (diff(mdet, 0) == 0) return false;
    ld t1 = -outer(b.pos - a.pos, b.dir) / mdet;
    ld t2 = outer(a.dir, b.pos - a.pos) / mdet;
    if (!is_between(t1, 0, 1) || !is_between(t2, 0, 1)) return false;
    return true;
}

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    unordered_map<ll,vector<pll>>mpx,mpy;
    vector<vector<ll>>grp(n);
    vector<pll>arr(n);
    vector<pair<Line,pll>>hor,ver;
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        mpx[arr[i].first].push_back({arr[i].second,i});
        mpy[arr[i].second].push_back({arr[i].first,i});
    }
    for(auto&[x,vy]:mpx){
        sort(vy.begin(),vy.end());
        if(vy.size()&1){
            cout<<"NO\n";
            return;
        }
        for(i=1;i<vy.size();i+=2){
            grp[vy[i].second].push_back(vy[i-1].second);
            grp[vy[i-1].second].push_back(vy[i].second);
            hor.push_back({Line{
                    Point{(ld) x, (ld) vy[i - 1].first},
                    Point{0, (ld) (vy[i].first - vy[i - 1].first)}
            },{vy[i].second,vy[i-1].second}});
        }
    }
    for(auto&[y,vx]:mpy){
        sort(vx.begin(),vx.end());
        if(vx.size()&1){
            cout<<"NO\n";
            return;
        }
        for(i=1;i<vx.size();i+=2){
            grp[vx[i].second].push_back(vx[i-1].second);
            grp[vx[i-1].second].push_back(vx[i].second);
            ver.push_back({Line{
                    Point{(ld) vx[i - 1].first, (ld) y},
                    Point{(ld) (vx[i].first - vx[i - 1].first), 0}
            },{vx[i].second,vx[i-1].second}});
        }
    }
    for(i=0;i<hor.size();i++){
        for(j=0;j<ver.size();j++){
            set<ll>st({hor[i].second.first,hor[i].second.second,ver[j].second.first,ver[j].second.second});
            if(st.size()<4)continue;
            if(get_segment_cross(hor[i].first,ver[j].first)){
                cout<<"NO\n";
                return;
            }
        }
    }
    vector<bool>vis(n);
    queue<ll>q({0});
    vis[0]=true;
    while(!q.empty()){
        ll now=q.front();
        q.pop();
        for(auto& x:grp[now]){
            if(!vis[x]){
                vis[x]=true;
                q.push(x);
            }
        }
    }
    for(i=0;i<n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}
