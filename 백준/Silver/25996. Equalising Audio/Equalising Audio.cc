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

void solve(ll testcase) {
    ll i, j, k;
    ll n,x;
    ld sum=0;
    cin>>n>>x;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i]*arr[i];
    }
    sum/=n;
    ld l=sum/x;
    for(i=0;i<n;i++){
        if(sum==0)cout<<"0 ";
        else cout<<fixed<<setprecision(10)<<arr[i]/sqrt(l)<<' ';
    }
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