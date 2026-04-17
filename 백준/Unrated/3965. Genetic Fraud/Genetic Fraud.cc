#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;
using pld = pair<ld, ld>;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void solve() {
    ll N;
    cin >> N;
    string str1, str2;
    cin >> str1 >> str2;
    for(auto i = 1 ; 2 * i <= N; i++) {
        ll streak = 0;
        for(auto j = 0; j < N - i; j++) {
            if(abs(int(str1[j] - str2[j + i])) <= 1) {
                streak++;
                if(streak >= ((N + 1) >> 1)) {cout << "POSITIVE\n"; return;}
            }
            else streak = 0;
        }
    }
    for(auto i = 0; 2 * i <= N; i++) {
        ll streak = 0;
        for(auto j = i; j < N; j++) {
            if(abs(int(str1[j] - str2[j-i])) <= 1) {
                streak++;
                if(streak >= ((N + 1) >> 1)) {cout << "POSITIVE\n"; return;}
            }
            else streak = 0;
        }
    }
    cout << "NEGATIVE\n";
}

int main(){
    setup();
    ll t;
    cin >> t;
    for(auto tc = 0; tc < t; tc++) {
        solve();
    }
}
