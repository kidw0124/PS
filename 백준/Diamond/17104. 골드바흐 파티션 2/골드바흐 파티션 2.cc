#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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

void fft(int sign, ll n, float *real, float *imag) {
    double theta = sign * 2 * M_PI / n;
    int x=1;
    for (ll m = n; m >= 2; m >>= 1, x <<= 1) {
        double wr = 1, wi = 0, c = cos(theta*x), s = sin(theta*x);
        for (ll i = 0, mh = m >> 1; i < mh; ++i) {
            for (ll j = i; j < n; j += m) {
                ll k = j + mh;
                float xr = real[j] - real[k], xi = imag[j] - imag[k];
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
const ll maxn = 2e6+1;
int ans[maxn];
bitset<(int)5e5+1> primes;
void mult() {
    ll fn = 1048576; // n + m: interested length
    static float ra[maxn],ia[maxn];
    for (ll i = 0; i < 5e5+1; ++i) ra[i] = primes[i], ia[i] = 0;
    for (ll i = 5e5+1; i < fn; ++i) ra[i] = ia[i] = 0;
    fft(1, fn, ra, ia);
    for (ll i = 0; i < fn; ++i) {
        float real = ra[i] * ra[i] - ia[i] * ia[i];
        float imag = ra[i] * ia[i] * 2;
        ra[i] = real, ia[i] = imag;
    }
    fft(-1, fn, ra, ia);
    for (ll i = 0; i < fn; ++i) ans[i] = (int)round(ra[i] / fn );
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n;
    primes.set();
    primes[0]=0;
    for(i=1;i<=5e5;i++){
        if(primes[i]){
            for(j=i+(i<<1|1);j<=5e5;j+=(i<<1|1)){
                primes[j]=0;
            }
        }
    }
    mult();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==4)cout<<"1\n";
        else cout<<(ans[(n-2)/2]+1)/2<<'\n';
    }
    return 0;
}
