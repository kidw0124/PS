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

vector<string> s(5), res(5, "zzzzzzzzz"), tmp(5, ".........");
vector<ll> cnt(12);
set<ll> st;

void process(ll x)
{
    if(x == 12) {
        if(s[0][4] != 'x' && s[0][4] != cnt[0] + 'A' - 1)return;
        if(s[1][1] != 'x' && s[1][1] != cnt[9] + 'A' - 1)return;
        if(s[1][3] != 'x' && s[1][3] != cnt[1] + 'A' - 1)return;
        if(s[1][5] != 'x' && s[1][5] != cnt[8] + 'A' - 1)return;
        if(s[1][7] != 'x' && s[1][7] != cnt[11] + 'A' - 1)return;
        if(s[2][2] != 'x' && s[2][2] != cnt[2] + 'A' - 1)return;
        if(s[2][6] != 'x' && s[2][6] != cnt[7] + 'A' - 1)return;
        if(s[3][1] != 'x' && s[3][1] != cnt[3] + 'A' - 1)return;
        if(s[3][3] != 'x' && s[3][3] != cnt[4] + 'A' - 1)return;
        if(s[3][5] != 'x' && s[3][5] != cnt[5] + 'A' - 1)return;
        if(s[3][7] != 'x' && s[3][7] != cnt[6] + 'A' - 1)return;
        if(s[4][4] != 'x' && s[4][4] != cnt[10] + 'A' - 1)return;
        tmp[0][4] = cnt[0] + 'A' - 1;
        tmp[1][1] = cnt[9] + 'A' - 1;
        tmp[1][3] = cnt[1] + 'A' - 1;
        tmp[1][5] = cnt[8] + 'A' - 1;
        tmp[1][7] = cnt[11] + 'A' - 1;
        tmp[2][2] = cnt[2] + 'A' - 1;
        tmp[2][6] = cnt[7] + 'A' - 1;
        tmp[3][1] = cnt[3] + 'A' - 1;
        tmp[3][3] = cnt[4] + 'A' - 1;
        tmp[3][5] = cnt[5] + 'A' - 1;
        tmp[3][7] = cnt[6] + 'A' - 1;
        tmp[4][4] = cnt[10] + 'A' - 1;
        res = min(res, tmp);
        return;
    }

    else if(x == 3) {
        cnt[3] = 26 - cnt[0] - cnt[1] - cnt[2];
        if(cnt[3] <= 0)return;
        if(st.find(cnt[3]) == st.end())return;
        st.erase(cnt[3]);
        process(4);
        st.insert(cnt[3]);
    }

    else if(x == 6) {
        cnt[6] = 26 - cnt[3] - cnt[4] - cnt[5];
        if(cnt[6] <= 0)return;
        if(st.find(cnt[6]) == st.end())return;
        st.erase(cnt[6]);
        process(7);
        st.insert(cnt[6]);
    }

    else if(x == 8) {
        cnt[8] = 26 - cnt[0] - cnt[6] - cnt[7];
        if(cnt[8] <= 0)return;
        if(st.find(cnt[8]) == st.end())return;
        st.erase(cnt[8]);
        process(9);
        st.insert(cnt[8]);
    }

    else if(x == 10) {
        cnt[10] = 26 - cnt[9] - cnt[2] - cnt[4];
        if(cnt[10] <= 0)return;
        if(st.find(cnt[10]) == st.end())return;
        st.erase(cnt[10]);
        process(11);
        st.insert(cnt[10]);
    }

    else if(x == 11) {
        cnt[11] = 26 - cnt[9] - cnt[1] - cnt[8];
        if(cnt[11] <= 0)return;
        if(st.find(cnt[11]) == st.end())return;
        st.erase(cnt[11]);
        process(12);
        st.insert(cnt[11]);
    }

    else {
        for(ll k = 1; k <= 12; k++) {
            if(st.find(k) != st.end()) {
                st.erase(k);
                cnt[x] = k;
                process(x + 1);
                st.insert(k);
            }
        }
    }
}

void solve() {
    ll n = 5, i;
    for(i = 0; i < n; i++)cin >> s[i];
    for(i = 1; i <= 12; i++)st.insert(i);
    process(0);
    for(i = 0; i < n; i++)cout << res[i] << "\n";
}

int main(){
    setup();
    ll t;
    t = 1;
    //cin >> t;
    for(ll tc = 0; tc < t; tc++) {
        solve();
    }
}
