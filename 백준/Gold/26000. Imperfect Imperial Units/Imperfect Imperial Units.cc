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
#define debug if constexpr(ddebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (ddebug) { cout << "[DEBUG] " << #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto &x : a)

void setup() {
    if(ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() {
    ll i, j, k;
}

void solve(ll testcase) {
    ll i,j,k;
    ll n,q;
    cin>>n>>q;
    set<string>st;
    vector<string>units;
    map<string,ll>mp;
    vector<pair<ld,pair<string,string>>>arr(n);
    vector<vector<ld>>adj(101,vector<ld>(101));
    for(i=0;i<101;i++)adj[i][i]=1;
    for(i=0;i<n;i++){
        string str1,str2;
        ll a,b;
        ld kk;
        char c;
        cin>>j>>str1>>c>>kk>>str2;
        if(st.find(str1)==st.end()){
            st.insert(str1);
            mp[str1]=a=units.size();
            units.push_back(str1);
        }
        else a=mp[str1];
        if(st.find(str2)==st.end()){
            st.insert(str2);
            mp[str2]=b=units.size();
            units.push_back(str2);
        }
        else b=mp[str2];
        arr[i]={kk, {str1, str2}};
        adj[a][b]=kk;
        adj[b][a]=(ld)1/kk;
    }
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            for(k=0;k<101;k++){
                if(adj[j][i]&&adj[i][k]&&!adj[j][k]){
                    adj[j][k]=adj[j][i]*adj[i][k];
                }
            }
        }
    }
    for(i=0;i<q;i++){
        string str1,to,str2;
        ld m;
        cin>>m>>str1>>to>>str2;
        ll a=mp[str1],b=mp[str2];
        if(adj[a][b]){
            cout<< setprecision(10)<<m*adj[a][b]<<'\n';
        }
        else cout<<"impossible\n";
    }
}

int main()
{
    setup();
    preprocess();
    ll t = 1;
//    cin >> t;
    for(ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}