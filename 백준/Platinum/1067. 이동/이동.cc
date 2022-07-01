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
ll POW(ll a, ll b, ll rem=1ull<<63-1) {
    ll p=1;
    for(; b; b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;
    return p;
}

void fft(int sign, ll n, double *real, double *imag) {
    double theta = sign * 2 * acos(-1) / n;
    for (ll m = n; m >= 2; m >>= 1, theta *= 2) {
        double wr = 1, wi = 0, c = cos(theta), s = sin(theta);
        for (ll i = 0, mh = m >> 1; i < mh; ++i) {
            for (ll j = i; j < n; j += m) {
                ll k = j + mh;
                double xr = real[j] - real[k], xi = imag[j] - imag[k];
                real[j] += real[k], imag[j] += imag[k];
                real[k] = wr * xr - wi * xi, imag[k] = wr * xi + wi * xr;
            }
            double _wr = wr * c - wi * s, _wi = wr * s + wi * c;
            wr = _wr, wi = _wi;
        }
    }
    for (ll i = 1, j = 0; i < n; ++i) {
        for (ll k = n >> 1; k > (j ^= k); k >>= 1);
        if (j < i) swap(real[i], real[j]), swap(imag[i], imag[j]);
    }
}
// Compute Poly(a)*Poly(b), write to r; Indexed from 0
// O(n*logn)
vector<ll>mult(vector<ll>&a, ll n, vector<ll>&b, ll m) {
    const ll maxn = 8*(60000+5);
    static double ra[maxn], rb[maxn], ia[maxn], ib[maxn];
    ll fn = 1;
    while (fn < n + m) fn <<= 1; // n + m: interested length
    for (ll i = 0; i < n; ++i) ra[i] = a[i], ia[i] = 0;
    for (ll i = n; i < fn; ++i) ra[i] = ia[i] = 0;
    for (ll i = 0; i < m; ++i) rb[i] = b[i], ib[i] = 0;
    for (ll i = m; i < fn; ++i) rb[i] = ib[i] = 0;
    fft(1, fn, ra, ia);
    fft(1, fn, rb, ib);
    for (ll i = 0; i < fn; ++i) {
        double real = ra[i] * rb[i] - ia[i] * ib[i];
        double imag = ra[i] * ib[i] + rb[i] * ia[i];
        ra[i] = real, ia[i] = imag;
    }
    fft(-1, fn, ra, ia);
    vector<ll>ret(fn);
    for (ll i = 0; i < fn; ++i) ret[i] = (ll)round(ra[i] / fn );
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<ll>a(n*2),b(n);
    for(i=0; i<n; i++) {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(i=n-1; i>=0; i--) {
        cin>>b[i];
    }
    vector<ll> ans=mult(a,n*2,b,n);

    cout<<*max_element(all(ans));
    return 0;
}
