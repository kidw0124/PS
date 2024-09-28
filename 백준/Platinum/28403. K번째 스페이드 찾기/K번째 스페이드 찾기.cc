#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#ifdef ONLINE_JUDGE
constexpr bool XDEBUG = false;
#else
constexpr bool XDEBUG = true;
#endif


void setup(){
    if(XDEBUG){
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i, j, k;
}

void solve(ll testcase){
    ll i, j, k;
    ll n, res, cur, p;
    string s;
    cin >> n >> s;
    vector<ll> a(2*n + 1), st(2*n + 1, n + 1), ed(2*n + 1), know(2*n + 1, n);
    st[0] = 0;
    for(i = 1; i <= n; i++) {
        if(s[i - 1] == 'S')a[i] = 1;
        a[i] += a[i - 1];
        st[a[i]] = min(st[a[i]], i);
        ed[a[i]] = max(ed[a[i]], i);
        know[a[i] + (n - i) + 1] = min(know[a[i] + (n - i) + 1], i);
    }

    for(i = 1; i <= n; i++) {
        res = 0;
        cur = 0;
        p = know[i];
        while(a[cur] != i) {
            ll tmp = (ed[a[cur]] - cur) / (i - a[cur]) + 1;
            if(cur + (i - a[cur]) * tmp >= p) {
                tmp = (p - cur - 1) / (i - a[cur]) + 1;
                res += tmp;
                break;
            }
            res += tmp;
            cur += (i - a[cur]) * tmp;
        }
        cout << res << " ";
    }
    return;
}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(i+1);
    }
}