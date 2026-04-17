#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if(ddebug)cout << "[DEBUG] "
#define debugv(x) debug << #x << " : " << x << "\n";
#define debugc(x) if(ddebug){debug << #x << " : ";for(auto k:x)cout<<k<<", ";cout<<"\n";}

using ll = long long;
using ld = long double;
using LL = __int128_t;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
}

void preprocess() {
    ll i, j;
}

const ll MATSZ = 64;

inline bool is_zero(ld a) {
    return abs(a) < 1e-9;
}

ld inverse_and_det(ll n, ld A[][MATSZ], ld out[][MATSZ]) {
    ld det = 1;
    for (ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            out[i][j] = 0;
        }
        out[i][i] = 1;
    }
    for(ll i = 0; i < n; i++) {
        if(is_zero(A[i][i])) {
            ld maxv = 0;
            ll maxid = -1;
            for(ll j = i + 1; j < n; j++) {
                auto cur = abs(A[j][i]);
                if(maxv < cur) {
                    maxv = cur;
                    maxid = j;
                }
            }
            if(maxid == -1 || is_zero(A[maxid][i]))return 0;
            for(ll k = 0; k < n; k++) {
                A[i][k] += A[maxid][k];
                out[i][k] += out[maxid][k];
            }
        }
        det *= A[i][i];
        ld coeff = 1.0 / A[i][i];
        for(ll j = 0; j < n; j++)A[i][j] *= coeff;
        for(ll j = 0; j < n; j++)out[i][j] *= coeff;
        for(ll j = 0; j < n; j++) {
            if(j != i) {
                ld mp = A[j][i];
                for(ll k = 0; k < n; k++)A[j][k] -= A[i][k] * mp;
                for(ll k = 0; k < n; k++)out[j][k] -= out[i][k] * mp;
            }
        }
    }
    return det;
}

const ld EPS = 1e-300;
using vvd= vector<vector<ld>>;

bool gauss_jordan(vvd& a, vvd& b) {
    const ll n = a.size();
    const ll m = b[0].size();
    vector<ll> irow(n), icol(n), ipiv(n);
    for(ll i = 0; i < n; i++) {
        ll pj = -1, pk = -1;
        for(ll j = 0; j < n; j++) {
            if(!ipiv[j]) {
                for(ll k = 0; k < n; k++) {
                    if(!ipiv[k]) {
                        if(pj == -1 || abs(a[j][k]) > abs(a[pj][pk])) {
                            pj = j;
                            pk = k;
                        }
                    }
                }
            }
        }
        if(abs(a[pj][pk]) < EPS)return false;
        ipiv[pk]++;
        swap(a[pj], a[pk]);
        swap(b[pj], b[pk]);
        irow[i] = pj;
        icol[i] = pk;
        ld c = 1 / a[pk][pk];
        a[pk][pk] = 1;
        for(ll p = 0; p < n; p++)a[pk][p] *= c;
        for(ll p = 0; p < m; p++)b[pk][p] *= c;
        for(ll p = 0; p < n; p++) {
            if (p != pk) {
                c = a[p][pk];
                a[p][pk] = 0;
                for (ll q = 0; q < n; q++)a[p][q] -= a[pk][q] * c;
                for (ll q = 0; q < m; q++)b[p][q] -= b[pk][q] * c;
            }
        }
    }
    for(ll p = n - 1; p >= 0; p--) {
        if(irow[p] != icol[p]) {
            for(ll k = 0; k < n; k++)swap(a[k][irow[p]], a[k][icol[p]]);
        }
    }
    return true;
}

void solve(ll testcase) {
    ll i, j, k;
    ll n, m;
    ld p;
    cin>>n>>m>>p;
    vvd a(1<<n,vector<ld>(1<<n));
    vvd b(1<<n,vector<ld>(1));
    for(i=0;i<(1<<n);i++){
        ll cnt=0;
        for(j=0;j<n;j++){
            cnt+=i>>j&1;
        }
        a[i][i]=1;
        if(cnt<m) {
            b[i][0]=1;
            ll q = ((~(1 << (n-1))) & i) << 1;
            a[i][q] -= 1-p;
            a[i][q|1]-=p;
        }
    }
    for(auto k:a){
        debugc(k);
    }
    gauss_jordan(a,b);
    cout<<fixed<<setprecision(10)<<b[0][0];
}

int main() {
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll i = 1; i <= t; i++)solve(i);
    return 0;
}