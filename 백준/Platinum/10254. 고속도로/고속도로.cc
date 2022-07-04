#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a, ll b) {
    if(a&&b)return a*(b/gcd(a,b));
    return a+b;
}
ll POW(ll a, ll b, ll rem) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}
inline int diff(ll lhs, ll rhs) {
    if (lhs <= rhs && rhs <= lhs) return 0;
    return (lhs < rhs) ? -1 : 1;
}

struct Point {
    ll x, y;
    bool operator==(const Point& rhs) const {
        return diff(x, rhs.x) == 0 && diff(y, rhs.y) == 0;
    }
    Point operator+(const Point& rhs) const {
        return Point{ x + rhs.x, y + rhs.y };
    }
    Point operator -(const Point& rhs) const {
        return Point{ x - rhs.x, y - rhs.y };
    }
    Point operator*(ll t) const {
        return Point{ x * t, y * t };
    }
};

inline ll outer(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}
inline int ccw(const Point& a, const Point& b, const Point& c) {
    return diff(outer(b - a, c - a), 0);
}

vector<pair<Point,Point>> antipodal_pairs(vector<Point>& pt) {
    sort(pt.begin(), pt.end(), [](const Point& a, const Point& b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });
    vector<Point> up, lo;
    vector<pair<Point,Point>>ret;
    for (const auto& p : pt) {
        while (up.size() >= 2 && ccw(*++up.rbegin(), *up.rbegin(), p) >= 0) up.
            pop_back();
        while (lo.size() >= 2 && ccw(*++lo.rbegin(), *lo.rbegin(), p) <= 0) lo.
            pop_back();
        up.emplace_back(p);
        lo.emplace_back(p);
    }
    for (int i = 0, j = (int)lo.size() - 1; i + 1 < up.size() || j > 0; ) {
        ret.push_back({up[i], lo[j]}); // DO WHAT YOU WANT
        if (i + 1 == up.size()) {
            --j;
        }
        else if (j == 0) {
            ++i;
        }
        else if ((long long)(up[i + 1].y - up[i].y) * (lo[j].x - lo[j - 1].x)
                 > (long long)(up[i + 1].x - up[i].x) * (lo[j].y - lo[j - 1].y))
        {
            ++i;
        }
        else {
            --j;
        }
    }
    return ret;
}

ll disqst(pair<Point,Point>pa) {
    auto a=pa.first,b=pa.second;
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,t;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<Point>arr(n);
        for(i=0; i<n; i++) {
            cin>>arr[i].x>>arr[i].y;
        }
        auto k=antipodal_pairs(arr);
        ll disq=0;
        pair<Point,Point>ans;
        for(auto kk:k) {
            if(disq<disqst(kk)) {
                ans=kk;
                disq=disqst(kk);
            }
        }
        cout<<ans.first.x<<' '<<ans.first.y<<' '<<ans.second.x<<' '<<ans.second.y<<'\n';
    }
    return 0;
}
