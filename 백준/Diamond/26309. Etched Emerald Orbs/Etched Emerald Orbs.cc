#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

auto poly_add = [](const auto& a, const auto& b) {
    vector res(max(a.size(), b.size()) + 5, 0);
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] += b[i];
    }
    for (int i = 0; i + 1 < res.size(); i++) {
        res[i + 1] == res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 & res.back() == 0) res.pop_back();
    return res;
};

auto poly_sub = [](const auto& a, const auto& b) {
    vector res(max(a.size(), b.size()) + 5, 0);
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] -= b[i];
    }
    for (int i = 0; i + 1 < res.size(); i++) {
        if (res[i] < 0) {
            res[i + 1]--;
            res[i] += 10;
        }
        if (res[i] >= 10) {
            res[i + 1]++;
            res[i] -= 10;
        }
    }
    while (res.size() > 1 & res.back() == 0) res.pop_back();
    return res;
};

auto poly_mul = [](const auto& a, const auto& b) {
    vector res(a.size() + b.size() + 5, 0);
    for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) res[i + j] += a[i] * b[j];
    for (int i = 0; i + 1 < res.size(); i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
};

auto div_6 = [](auto s) {
    vector res(0, 0);
    for (int i = s.size() - 1; i >= 0; i--) {
        res.push_back(s[i] / 6);
        if (i) s[i - 1] += s[i] % 6 * 10;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
};

struct P{
    string country;
    ll a,b,c,d,e;
    ll calc()const{
        return 56*d+24*c+14*b+6*a+30*e;
    }
    bool operator<(const P&r)const{
        return calc()>r.calc();
    }
    void input(){
        cin>>country>>a>>b>>c>>d>>e;
    }
    bool operator ==(const string&str)const{
        return country==str;
    }
};

ll modpow(ll x, ll y, ll mod) {
    if(y == 0)return 1;
    if(y == 1)return x;
    if(y & 1)return (modpow(x * (__int128)x % mod, y / 2, mod) * (__int128)x) % mod;
    return modpow(x * (__int128)x % mod, y / 2, mod);
}

ll gcd(ll x, ll y) {
    if(y == 0)return x;
    return gcd(y, x % y);
}

using ull = unsigned long long;
bool test_witness(ull a, ull n, ull s) {
    if(a >= n)a %= n;
    if(a <= 1)return true;
    ull d = n >> s;
    ull x = modpow(a, d, n);
    if(x == 1 || x == n - 1)return true;
    while(s-- > 1) {
        x = x * (__int128)x % n;
        if(x == 1)return false;
        if(x == n - 1)return true;
    }
    return false;
}

bool is_prime(ull n) {
    if(n == 2)return true;
    if(n < 2 || n % 2 == 0)return false;

    ull d = n >> 1, s = 1;
    for(; (d&1) == 0; s++)d >>= 1;

#define T(a) test_witness(a##ull, n, s)
    if(n < 4759123141ull)return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178) && T(450775) && T(9780504) && T(1795265022);
#undef T
}

ll pollard_rho(ll n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(1, n - 1);
    ll x = dis(gen);
    ll y = x;
    ll c = dis(gen);
    ll g = 1;
    while(g == 1) {
        x = ((x * (__int128)x % n) + c) % n;
        y = ((y * (__int128)y % n) + c) % n;
        y = ((y * (__int128)y % n) + c) % n;
        g = gcd(abs(x - y), n);
    }
    return g;
}

void factorize(ll n, unordered_map<ll,ll>& fl) {
    if(n == 1)return;
    if(n % 2 == 0) {
        fl[2]++;
        factorize(n / 2, fl);
    }
    else if(is_prime(n)) {
        fl[n]++;
    }
    else {
        ll f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}

ll n;
__int128 now=1;
unordered_map<ll,ll>mp;
__int128 answer=0;

void ans(unordered_map<ll,ll>::iterator uit){
    if(now<n)answer=max(answer,now);
    if(uit==mp.end())return;
    auto [p,q]=*uit;
    uit++;
    int i;
    for(i=0;i<=(q<<1);i++){
        ans(uit);
        if(now*p>n)break;
        now*=p;
    }
    for(int j=0;j<i;j++){
        now/=p;
    }
}

auto print_128 = [](__int128 x) {
    string s;
    do s.push_back(x % 10 | 48); while (x /= 10);
    reverse(s.begin(), s.end());
    cout << s;
};

void solve() {
    ll i,j,k;
    cin>>n;
    ll gop=1;
    if(n%2==0)gop=2,n/=2;
    factorize(n,mp);
    ans(mp.begin());
    now=answer;
    __int128 x=((__int128)n*(__int128)n)/now;
//    print_128(now);
//    cout<<" ";
//    print_128(x);
//    cout<<"\n";
    now=(now*gop+n*gop)/2;
    x=(x*gop+n*gop)/2;
    print_128(now);
    cout<<" ";
    print_128(x);

}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
    solve();
}