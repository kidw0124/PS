#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

constexpr ll mod = 1e9+7;

void preprocess(){
}

void solve(){
    ll n, m, i, p, res = 0, cur;
    priority_queue<ll, vector<ll>, greater<>> mnhp;
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        cin >> p;
        mnhp.push(p);
    }
    while((mnhp.size() - 1) % (m - 1) != 0)mnhp.push(0);

    while(mnhp.size() != 1) {
        cur = 0;
        for(i = 0; i < m; i++) {
            cur += mnhp.top();
            mnhp.pop();
        }
        res += cur;
        mnhp.push(cur);
    }

    cout << res << "\n";
}

int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    preprocess();
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++)solve();
}