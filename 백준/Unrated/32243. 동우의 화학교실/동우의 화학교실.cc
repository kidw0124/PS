#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
#define int ll
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)

#define debug if constexpr (xdebug) cout << "[DEBUG] "

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif

int gcd(int a, int b){return b?gcd(b,a%b):a;}

int POW(int a, int b, int rem){
    int p=1;
    for(; b; b >>= 1, a = a*(ll)a%rem) {
        if(b&1) p = p*(ll)a%rem;
    }
    return p;
}

pair<int, int> extended_gcd(int a, int b) {
    if(b == 0) return {1, 0};
    auto t = extended_gcd(b, a % b);
    return {t.second, t.first - t.second * (a / b)};
}
int modinverse(int a, int m) {
    return (extended_gcd(a, m).first % m + m) % m;
}

bool test_witness(int a, int n, int s) {
    if(a >= n) a %= n;
    if(a <= 1) return true;
    int d = n >> s;
    int x = POW(a, d, n);
    if(x == 1 || x == n - 1) return true;
    while(s-- > 1) {
        x = x * x % n;
        if(x == 1) return false;
        if(x == n - 1) return true;
    }
    return false;
}
bool is_prime(int n) {
    if(n == 2) return true;
    if(n < 2 || n % 2 == 0) return false;

    int d = n >> 1, s = 1;
    for(; (d&1) == 0; s++) d >>= 1;

#define T(a) test_witness(a, n, s)
    if(n < 4759123141ll) return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178) &&
           T(450775) && T(9780504) && T(1795265022);
#undef T
}
int pollard_rho(int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, n - 1);
    int x = dis(gen);
    int y = x;
    int c = dis(gen);
    int g = 1;
    while(g == 1) {
        x = (x*(ll)x%n + c) % n;
        y = (y*(ll)y%n + c) % n;
        y = (y*(ll)y%n + c) % n;
        g = gcd((x > y ? x - y : y - x), n);
    }
    if(g == n) g = pollard_rho(n);
    return g;
}
void factorize(int n, map<int, int>& factor_map) {
    if(n == 1) return;
    if(n % 2 == 0) {
        factor_map[2]++;
        factorize(n >> 1, factor_map);
    }
    else if(is_prime(n)) factor_map[n]++;
    else {
        int f = pollard_rho(n);
        factorize(f, factor_map);
        factorize(n / f, factor_map);
    }
}

int find_primroot(int p, int e) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, p - 1);
    map<int, int> pm1_factors;
    factorize(p - 1, pm1_factors);
    vector<int> crits;
    for(auto [q, exponent] : pm1_factors) {
        crits.push_back((p - 1) / q);
    }
    int x;
    while(true) {
        x = dis(gen);
        bool flag = true;
        each(crit, crits) {
            if(POW(x, crit, p) == 1) {flag = false; break;}
        }
        if(flag) break;
    }
    if(e > 1 && POW(x, p - 1, p * p) == 1) x = (x + p) % (p * p);
    return x;
}

void solve(int testcase){
    int N;
    cin >> N;
    map<int, int> N_factors;
    factorize(N, N_factors);
    vector<int> N_prime_pow_factors, CRT_mods, CRT_baselines;
    for(auto& [p, e] : N_factors) {
        ll temp1 = 1, temp2 = N;
        rep(i, 0, e) {temp1 *= p, temp2 /= p;}
        N_prime_pow_factors.push_back(temp1);
        CRT_mods.push_back(temp2);
        CRT_baselines.push_back(temp2*modinverse(temp2, temp1)%N);
    }
    int generator_baseline = 0;
    each(item, CRT_baselines) {
        generator_baseline = (generator_baseline + item) % N;
    }

    map<int, pair<int, int>> direct_sum_decomp;
    int idx = 0;
    for(auto& [p, e] : N_factors) {
        if(!idx && p == 2) {
            if(e <= 2) {
                if(e == 1) {idx++; continue;}
                ll g = (generator_baseline + 2 * CRT_baselines[0]) % N;
                if(direct_sum_decomp[2].first < 1) direct_sum_decomp[2] = {1, g};
            } else {
                ll g = (generator_baseline + 2 * CRT_baselines[0]) % N;
                if(direct_sum_decomp[2].first < e - 2) direct_sum_decomp[2] = {e - 2, g};
                g = (generator_baseline + (e == 3 ? 4 : (1ll<<(e-1)) - 2)*CRT_baselines[0]) % N;
                if(direct_sum_decomp[2].first < 1) direct_sum_decomp[2] = {1, g};
            }
        } else {
            int x = find_primroot(p, e);
            int primroot_order = 1;
            rep(i, 0, e - 1) primroot_order *= p;
            primroot_order *= (p - 1);
            map<int, int> primroot_order_factors;
            factorize(p - 1, primroot_order_factors);
            if(e > 1) primroot_order_factors[p] += (e - 1);
            for(auto [q, f] : primroot_order_factors) {
                ll temp1 = 1, temp2 = primroot_order;
                rep(i, 0, f) {temp1 *= q, temp2 /= q;}
                ll g = (generator_baseline +
                        (POW(x, temp2, N_prime_pow_factors[idx]) - 1) * CRT_baselines[idx]) % N;
                if(direct_sum_decomp[q].first < f) direct_sum_decomp[q] = {f, g};
            }
        }
        idx++;
    }

    ll Z = 1, G = 1;
    vector<int> inv_gs;
    for(auto& [p, tup] : direct_sum_decomp) {
        auto [e, g] = tup;
        rep(_, 0, e) Z *= p;
        G = G*g % N;
        inv_gs.push_back(modinverse(g, N));
    }
    ll inv_G = modinverse(G, N);
    vector<int> Z_prime_pow_factors;
    CRT_mods.clear(), CRT_baselines.clear();
    vector<int> giantstep_size;
    vector<__gnu_pbds::gp_hash_table<ll, int>> giantsteps;
    for(auto& [p, tup] : direct_sum_decomp) {
        auto [e, g] = tup;
        ll temp1 = 1, temp2 = Z;
        rep(i, 0, e) temp1 *= p, temp2 /= p;
        Z_prime_pow_factors.push_back(temp1);
        CRT_mods.push_back(temp2);
        CRT_baselines.push_back(temp2 * modinverse(temp2, temp1) % Z);

        giantsteps.emplace_back();
        int sz = max(1ll, (ll)ceil(sqrt(temp1 - 0.5)) / 5);
        giantstep_size.push_back(sz);
        ll temp_b = 1, multiplier = POW(g, sz, N);
        rep(j, 0, temp1 / sz) {
            giantsteps.back()[temp_b] = j;
            temp_b = temp_b * multiplier % N;
        }
    }
    int debug_idx = 0;
    if(xdebug) for(auto& [p, tup] : direct_sum_decomp) {
            debug << p << '\n';
            debug << tup.first << ' ' << tup.second;
            each(item, N_prime_pow_factors) cout << ' ' << tup.second % item;
            cout << ' ' << Z_prime_pow_factors[debug_idx] << ' ' << CRT_mods[debug_idx] << ' ' << CRT_baselines[debug_idx] << '\n';
            // cout << giantstep_size[debug_idx] << ' ';
            // each(item, giantsteps[debug_idx]) cout << '(' << item.first << ", " << item.second << ") ";
            // cout << '\n';
            debug_idx++;
        }
    cout << Z + 1 << '\n';
    cout << flush;

    int X, Y;
    cin >> X >> Y;
    rep(i, 0, X + Y) {
        rep(j, 0, X + Y) cout << (i == j ? (i < X ? inv_G : G) : 1) << ' ';
        cout << '\n';
    }
    cout << flush;

    ll a;
    rep(_, 0, X + Y) {
        cin >> a;
        ll ans = 0;
        rep(i, 0, Z_prime_pow_factors.size()) {
            ll a_p = POW(a, CRT_baselines[i], N);
            ll r = 0;
            while(giantsteps[i].find(a_p) == giantsteps[i].end()) {
                a_p = a_p*inv_gs[i]% N;
                r += 1;
            }
            ans += (r + giantstep_size[i] * giantsteps[i][a_p])*CRT_baselines[i]%Z;
        }
        ans %= Z;
        cout << (ans ? ans : Z) << ' ';
    }
    cout << '\n';
    cout << flush;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    clock_t st = clock();
    int t = 1;
    // cin >> t;
    rep(tc, 0, t) solve(tc);
    clock_t ed = clock();
    if(xdebug) {cout << '\n'; debug << ed - st << "ms\n";}
    return 0;
}
