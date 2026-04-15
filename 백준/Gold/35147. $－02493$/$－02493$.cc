#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= long double;
 
vector mpbig(10, vector(10, array<int, 4>()));
vector mpsmall(10, vector(10, vector(10, vector(10, 0))));
vector mpmix(10, vector(10, vector(10, array<int, 2>())));
void solve(int testcase) {
    int a,b;
    int N,M;
    cin>>N>>M>>a>>b;
    a %= 10, b %= 10;
    if (N >= 10 && M >= 10) {
        auto [q, w, e, r] = mpbig[a][b];
        cout<<(q*(ll)N - w)*M - e*(ll)N + r<<"\n";
    } else if (N < 10 && M < 10) {
        cout<<mpsmall[a][b][N][M]<<"\n";
    } else {
        if (N > M) {
            swap(N, M);
            swap(a, b);
        }
        auto [q, w] = mpmix[a][b][N];
        cout<<q*(ll)M - w<<"\n";
    }
}
 
void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}
 
void preprocess() {
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            vector<vector<int>> arr(10, vector<int>(10, 0));
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    arr[i][j] = (a * i + b * j) % 10;
                }
            }
            int q = 0, w = 0, e = 0, r = 0;
            auto &&mpss= mpsmall[a][b];
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; i * j <= 10; j++) {
                    int xx=0;
                    for (int x = 0; x < i; x++) {
                        for (int y = 0; y < j; y++) {
                            xx|=1<<arr[x][y];
                        }
                    }
                    if (__builtin_popcount(xx) == i * j) {
                        for(int pp=i;pp<10;pp++){
                            for(int qq=j;qq<10;qq++){
                                mpss[pp][qq]+=(pp - i + 1) * (qq - j + 1);
                            }
                        }
                        q++;
                        w += i - 1;
                        e += j - 1;
                        r += (i - 1) * (j - 1);
                    }
                }
            }
            mpbig[a][b] = {q, w, e, r};
        }
    }
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            vector<vector<int>> arr(10, vector<int>(10, 0));
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    arr[i][j] = (a * i + b * j) % 10;
                }
            }
            for (int N = 1; N < 10; N++) {
                int q = 0, w = 0;
                for (int i = 1; i <= N; i++) {
                    for (int j = 1; i * j <= 10; j++) {
                        int xx=0;
                        for (ll x = 0; x < i; x++) {
                            for (ll y = 0; y < j; y++) {
                                xx|=1<<arr[x][y];
                            }
                        }
                        if (__builtin_popcount(xx) == i * j) {
                            q += N - i + 1;
                            w += (N - i + 1) * (j - 1);
                        }
                    }
                }
                mpmix[a][b][N] = {q, w};
            }
        }
    }
}
 
signed main() {
    setup();
    preprocess();
    ll t = 1;
    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
