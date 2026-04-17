#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
using tlll = tuple<ll,ll,ll>;
using ld = long double;

#ifndef DLAS_HPP
#include <array>
#include <algorithm>
#include <functional>
#include <utility>

template<class T, class U>
T incMod(T x, U mod) {
    x += 1;
    return x == mod ? 0 : x;
}

template<class Domain, class CoDomain, size_t LEN = 5>
std::pair<Domain, CoDomain> dlas(
        std::function<CoDomain(Domain&)> f,
        std::function<void(Domain&)> mutate,
        Domain const& initial,
        uint64_t maxIdleIters = -1ULL
) {
    std::array<Domain, 3> S{initial, initial, initial};
    CoDomain curF = f(S[0]);
    size_t curPos = 0;
    size_t minPos = 0;

    std::array<CoDomain, LEN> fitness;
    std::fill(fitness.begin(), fitness.end(), curF);
    CoDomain minF = curF;
    size_t k = 0;

    for (uint64_t idleIters = 0; idleIters < maxIdleIters; idleIters += 1) {
        CoDomain prvF = curF;

        size_t newPos = incMod(curPos, 3);
        if (newPos == minPos) newPos = incMod(newPos, 3);

        Domain& curS = S[curPos];
        Domain& newS = S[newPos];

        newS = curS;
        mutate(newS);
        CoDomain newF = f(newS);
        if (newF < minF) {
            idleIters = 0;
            minPos = newPos;
            minF = newF;
        }
        if (newF == curF || newF < *std::max_element(fitness.begin(), fitness.end())) {
            curPos = newPos;
            curF = newF;
        }

        CoDomain& fit = fitness[k];
        if (curF > fit || curF < fit && curF < prvF) {
            fit = curF;
        }
        k = incMod(k, LEN);
    }
    return { S[minPos], minF };
}

#define DLAS_HPP
#endif

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>>arr(n,vector<ll>(n));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    auto gen_rand = [](int l, int r) {
        static random_device rnd;
        static mt19937 rd(rnd());
        return uniform_int_distribution(l, r)(rd);
    };
    auto f = [&](const vector<ll>&now){
        ll ret=0;
        for(ll i=0;i<n;i++){
            if(arr[now[i]][now[(i+1)%n]])ret++;
        }
        return -ret;
    };
    auto mutate = [&](vector<ll>&now){
        ll idx1 = gen_rand(0,n-1);
        swap(now[idx1],now[(idx1+1)%n]);
    };
    auto [ans,val] = make_pair(vector<ll>(n),0);
    for(ll i=0;i<50;i++){
        vector<ll>tmp(n);
        iota(tmp.begin(),tmp.end(),0);
        shuffle(tmp.begin(),tmp.end(),mt19937(random_device()()));
        auto [cur,cur_val] = dlas<vector<ll>,ll>(f,mutate,tmp,10'000);
        if(cur_val < val){
            val = cur_val;
            ans = cur;
        }
        if(val == -n)break;
    }
    if(val == -n){
        for(ll i=0;i<n;i++) {
            cout << ans[i] + 1 << ' ';
        }
    }
    else{
        cout << -1;
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc = 1;
//     cin >> tc;
    while (tc--) solve();
}