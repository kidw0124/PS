#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll, ll>;

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if constexpr (ddebug) cout << "[DEBUG] "


ll modpow(ll x,ll a, ll mod){
    ll ret=1;
    while(a){
        if(a&1)ret=(ret*x)%mod;
        x=(x*x)%mod;
        a>>=1;
    }
    return ret;
}

/*
 * Solve x for x^P = A mod Q
 * (P, Q-1) = 1 -> P^-1 mod (Q-1) exists
 * x has solution iff A^((Q-1) / P) = 1 mod Q
 * PP | (Q-1) -> P < sqrt(Q), solve lgQ rounds of discrete log
 * else -> find a s.t. s | (Pa - 1) -> ans = A^a */
using LL = long long;
LL mul(LL x, LL y, LL mod){ return (__int128) x * y % mod; }
LL add(LL x, LL y, LL mod){ return (x + y) % mod; }
LL pw(LL x, LL y, LL mod){
    LL ret = 1, piv = x;
    while(y){
        if(y & 1) ret = mul(ret, piv, mod);
        piv = mul(piv, piv, mod);
        y >>= 1;
    }
    return ret % mod;
}
void gcd(LL a, LL b, LL &x, LL &y, LL &g){
    if (b == 0) {
        x = 1, y = 0, g = a;
        return;
    }
    LL tx, ty;
    gcd(b, a%b, tx, ty, g);
    x = ty; y = tx - ty * (a / b);
}
LL P, A, Q, g; // x^P = A mod Q
const int X = 1e3;
LL base, ae[X], aXe[X], iaXe[X];
unordered_map<LL, LL> ht;
#define FOR(i, c) for (int i = 0; i < (c); ++i)
#define REP(i, l, r) for (int i = (l); i <= (r); ++i)
void build(LL a) { // ord(a) = P < sqrt(Q)
    base = a;
    ht.clear();
    ae[0] = 1; ae[1] = a; aXe[0] = 1; aXe[1] = pw(a, X, Q);
    iaXe[0] = 1; iaXe[1] = pw(aXe[1], Q-2, Q);
    REP(i, 2, X-1) {
        ae[i] = mul(ae[i-1], ae[1], Q);
        aXe[i] = mul(aXe[i-1], aXe[1], Q);
        iaXe[i] = mul(iaXe[i-1], iaXe[1], Q);
    }
    FOR(i, X) ht[ae[i]] = i;
}

LL dis_log(LL x) {
    FOR(i, X) {
        LL iaXi = iaXe[i];
        LL rst = mul(x, iaXi, Q);
        if (ht.count(rst)) return i*X + ht[rst];
    }
}
LL main2(ll _A, ll _Q) {
    A=_A,Q=_Q;
    P = 2;
    LL t = 0, s = Q-1;
    while (s % P == 0) {
        ++t;
        s /= P;
    }
    if (A == 0) return 0;
    if (t == 0) {
        // a^{P^-1 mod phi(Q)}
        LL x, y, _;
        gcd(P, Q-1, x, y, _);
        if (x < 0) {
            x = (x % (Q-1) + Q-1) % (Q-1);
        }
        LL ans = pw(A, x, Q);
        if (pw(ans, P, Q) != A) while(1);
        return ans;
    }
    // A is not P-residue
    if (pw(A, (Q-1) / P, Q) != 1) return -1;
    for (g = 2; g < Q; ++g) {
        if (pw(g, (Q-1) / P, Q) != 1)
            break;
    }
    LL alpha = 0;
    {
        LL y, _;
        gcd(P, s, alpha, y, _);
        if (alpha < 0) alpha = (alpha % (Q-1) + Q-1) % (Q-1);
    }
    if (t == 1) {
        LL ans = pw(A, alpha, Q);
        return ans;
    }
    LL a = pw(g, (Q-1) / P, Q);
    build(a);
    LL b = pw(A, add(mul(P%(Q-1), alpha, Q-1), Q-2, Q-1), Q);
    LL c = pw(g, s, Q);
    LL h = 1;
    LL e = (Q-1) / s / P; // r^{t-1}
    REP(i, 1, t-1) {
        e /= P;
        LL d = pw(b, e, Q);
        LL j = 0;
        if (d != 1) {
            j = -dis_log(d);
            if (j < 0) j = (j % (Q-1) + Q-1) % (Q-1);
        }
        b = mul(b, pw(c, mul(P%(Q-1), j, Q-1), Q), Q);
        h = mul(h, pw(c, j, Q), Q);
        c = pw(c, P, Q);
    }
    return mul(pw(A, alpha, Q), h, Q);
}

void solve(ll testcase){
    int i,j;
    ll p,a1,a2;
    cin>>p>>a1>>a2;
    ll d=(a2*a2%p-4*a1%p)%p;
    if(d<0)d+=p;
    auto get_sqrt=[](ll x,ll p)->ll{
        if(p==2){
            return x;
        }
        else{
            ll dp=(p-1)>>1;
            if(modpow(x,dp,p)==1){
                if((p&3)==3){
                    return modpow(x,(p+1)>>2,p);
                }
                else{
                    ll w=p-1,t=0;
                    while(w&1^1)w>>=1,t++;
                    ll z=1;
                    while(modpow(z,dp,p)==1)z++;
                    ll c=modpow(z,w,p),s=modpow(x,w,p),y=modpow(x,(w+1)>>1,p);
                    while(s>1){
                        ll tp=1;
                        while(modpow(s,1<<tp,p)!=1)tp++;
                        ll v=modpow(c,1<<(t-tp-1),p);
                        t=tp,c=v*v%p,y=y*v%p;
                        s=s*c%p;
                    }
                    return y;
                }
            }
            else return -1;
        }
    };
    ll sd=main2(d,p);
    debug<<d<<' '<<sd<<'\n';
    if(p==2){
        d=a1*2+a2;
        switch (d) {
            case 0:
                cout<<"0 0\n";
                break;
            case 1:
                cout<<"1 0\n";
                break;
            case 2:
                cout<<"1 1\n";
                break;
            case 3:
                cout<<"-1\n";
                break;
        }
    }
    else{
        if(sd==-1){
            cout<<"-1\n";
            return;
        }
        ll b1=(a2+sd)%p,b2=(a2-sd)%p;
        if(b1<0)b1+=p;
        if(b2<0)b2+=p;
        if(p==2){
            cout<<(b1>>1)<<' '<<(b2>>1)<<'\n';
        }
        else{
            cout<<(b1*(p+1)>>1)%p<<' '<<(b2*(p+1)>>1)%p<<'\n';
        }
    }
}

int main(){

#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t st = clock();
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t = 1;
     cin >> t;
    for(int i = 1; i <= t; i++) solve(i);
    clock_t ed = clock();
#ifdef kidw0124
    clock_t en = clock();
    cout << "Time: " << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
#endif
    return 0;
}