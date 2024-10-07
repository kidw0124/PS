#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

constexpr ll MOD=1e9+7;

ll modpow(ll x, ll n, ll mod=MOD){
    x%=mod;
    if(x<0)x+=MOD;
    ll ret=1;
    while(n){
        if(n&1)ret=(ret*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return ret;
}

vector<vector<ll>> matmul(const vector<vector<ll>>&a,const vector<vector<ll>>&b){
    return {{(a[0][0]*b[0][0]%MOD+a[0][1]*b[1][0]%MOD)%MOD,(a[0][0]*b[0][1]%MOD+a[0][1]*b[1][1]%MOD)%MOD},
            {(a[1][0]*b[0][0]%MOD+a[1][1]*b[1][0]%MOD)%MOD,(a[1][0]*b[0][1]%MOD+a[1][1]*b[1][1]%MOD)%MOD}};
}
vector<vector<ll>>matpow(vector<vector<ll>> a, ll n){
    vector<vector<ll>>ret({{1,0},{0,1}});
    while(n){
        if(n&1)ret=matmul(ret,a);
        a=matmul(a,a);
        n>>=1;
    }
    return ret;
}

ll modinv(ll x){
    x%=MOD;
    if(x<0)x+=MOD;
    return modpow(x,MOD-2);
}

void solve() {
    int i,j;
    ll n;
    ll a,b;
    cin>>a>>b>>n;
    ll cost=(b*b-a*a)%MOD*modinv(a*a+b*b)%MOD;
    if(cost<0)cost+=MOD;
    ll sint=2*a*b%MOD*modinv(a*a+b*b)%MOD;
    vector<vector<ll>>mat({{cost, MOD-sint},
                           {sint,cost}});
    mat=matpow(mat,n);
    ll x=(mat[0][0]*cost%MOD+mat[0][1]*sint%MOD)%MOD;
    if(n&1)x=MOD-x;
    cout<<x;
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