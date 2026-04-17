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
#define debug if constexpr(ddebug) cout << "[DEBUG] "<<'\n'

#ifndef kidw0124
const ll TSIZE = 1 << 20; // always 2^k form && n <= TSIZE
#else
const ll TSIZE = 1 << 3; // always 2^k form && n <= TSIZE
#endif

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

void preprocess() {
    ll i, j;


}

// extended euclidean algorithm and modular inverse
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modinv(ll a, ll m) {
    ll x, y;
    ll g = gcd(a, m, x, y);
    if (g != 1) {
        return -1;
    } else {
        x = (x % m + m) % m;
        return x;
    }
}

ll getcnt_tri(ll x, ll y){
    if(x+1<=y){
        return 1;
    }
    else return 0;
}

ll getcnt_sqr(ll x, ll y){
    ll ri = min(y,(ll)((x+1)/(sqrtl(6)-sqrtl(2))));
    debug<<ri<<' '<<y<<' '<<((x+1)/(sqrtl(6)-sqrtl(2)))<<' '<<(x/(sqrtl(6)-sqrtl(2)))<<'\n';
    return max(0ll,ri-(ll)(x/(sqrtl(6)-sqrtl(2))));
}

ll getcnt_circle(ll x, ll y){
    ll ri = min(y,(ll)((x+1)/sqrtl(3)));
    if(x==1){
        return 0;
    }
    if(x==2){
        return max(0ll,ri);
    }
    debug<<ri<<' '<<y<<' '<<((x+1)/sqrtl(3))<<' '<<(x/sqrtl(3))<<'\n';
    return max(0ll,ri-(ll)(x/sqrtl(3)));
}

void solve(ll testcase){
    ll i,j,k;
    ll n;
    cout<<fixed<<setprecision(2);
    cin>>n;
    ll grd=0;
    vector<ll> arr(n),brr(n);
    vector<string>type(n);
    ll ans=0;
    for(i=0;i<n;i++){
        cin>>type[i]>>brr[i];
        if(type[i]=="triangle"){
            arr[i]=brr[i]-1;
        }
        else if(type[i]=="square"){
            arr[i]=(ll)((ld)(sqrtl(6)-sqrtl(2))*brr[i]);
        }
        else{
            arr[i]=max(2ll,(ll)(sqrtl(3)*brr[i]));
        }
        grd^=arr[i];
    }
    for(i=0;i<n;i++){
        ll tmp=grd^arr[i];
        debug<<tmp<<' '<<arr[i]<<'\n';
        if(tmp>=arr[i]){
            continue;
        }
        if(type[i]=="triangle") {
            ans += getcnt_tri(tmp, brr[i]);
            debug<<ans<<'\n';
            ans += getcnt_sqr(tmp, (ll) (3 / (3 + 2 * sqrtl(3)) * brr[i]-(1e-10)));
            debug<<ans<<'\n';
            ans += getcnt_circle(tmp, (ll) (1 / (2 * sqrtl(3)) * brr[i]-(1e-10)));
            debug<<ans<<'\n';
        }
        else if(type[i]=="square"){
            ans += getcnt_tri(tmp, (ll) (2*sqrtl(2)/(1+sqrtl(3))*brr[i]-(1e-10)));
            debug<<ans<<'\n';
            ans += getcnt_sqr(tmp, brr[i]);
            debug<<ans<<'\n';
            ans += getcnt_circle(tmp, (ll) ((ld)0.5 * brr[i]-(1e-10)));
            debug<<ans<<'\n';
        }
        else{
            ans += getcnt_tri(tmp, (ll) (sqrtl(3) * brr[i]-(1e-10)));
            debug<<ans<<'\n';
            ans += getcnt_sqr(tmp, (ll) (sqrtl(2)*brr[i]-(1e-10)));
            debug<<ans<<'\n';
            ans += getcnt_circle(tmp, brr[i]);
            debug<<ans<<'\n';
        }
        debug<<"==="<<'\n';
    }
    cout<<ans<<'\n';



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
