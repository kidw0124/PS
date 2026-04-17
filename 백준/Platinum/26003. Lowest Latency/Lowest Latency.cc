#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (ddebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)

void setup() {
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

void preprocess() {
    ll i, j, k;
}
struct Point3d{
    ld x,y,z;
    bool operator<(const Point3d&r)const{
        return tuple<ll,ll,ll>({x,y,z})<tuple<ll,ll,ll>({r.x,r.y,r.z});
    }
};

ld dist(Point3d p, Point3d q) {
    ld x, y, z;
    x = p.x-q.x;
    y = p.y-q.y;
    z=p.z-q.z;
    ld ret = x * x + y * y + z * z;
    return sqrt(ret);
}

void solve(ll testcase) {
    ll i, j, k;
    ll n;
    cin >> n;
    vector<Point3d>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
    }
    sort(all(arr));
    ld ans=LLONG_MAX;
    for(i=0;i<n;i++){
        for(j=i+1;j<min(i+50,n);j++){
            ans=min(dist(arr[i],arr[j]),ans);
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}

