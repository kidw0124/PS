#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll,ll>;
const ll mod = 1e10;

ll modpow(ll x, ll y) {
    if(y == 0)return 1;
    if(y & 1)return modpow(x * x % mod, y / 2) * x % mod;
    return modpow(x * x % mod, y / 2);
}

vector<vector<ll>> operator*(const vector<vector<ll>>&a, const vector<vector<ll>>&b){
    vector<vector<ll>> ret(a.size(),vector<ll>(b[0].size()));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<b.size();k++){
                ret[i][j]+=(__int128)a[i][k]*b[k][j]%mod;
                ret[i][j]%=mod;
            }
        }
    }
    return ret;
}

vector<vector<ll>> operator^(const vector<vector<ll>>&a, ll b){
    vector<vector<ll>> ret(a.size(),vector<ll>(a.size()));
    vector<vector<ll>> now=a;
    for(int i=0;i<a.size();i++){
        ret[i][i]=1;
    }
    while(b){
        if(b&1){
            ret=ret*now;
        }
        now=now*now;
        b>>=1;
    }
    return ret;
}

ll fibo(ll n){
    vector<vector<ll>> mat={{1,1},{1,0}};
    mat=mat^(n-1);
    if(n==0)return 0;
    else return mat[0][0];
}

constexpr ll n=100'000'000;
using ordered_set = tree<ll, null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    vector<pll>arr(n);
    for(auto&[x,_]:arr)cin>>x;
    for(auto&[_,x]:arr)cin>>x;
    sort(arr.begin(), arr.end());
    ordered_set st;
    vector<ll>dp(n);
    ll sum=0;
    for(i=0;i<n;i++){
        dp[i]=i-st.order_of_key(arr[i].second);
        st.insert(arr[i].second);
        sum+=dp[i];
    }
    if(sum&1)cout<<"No\n";
    else{
        sum>>=1;
        vector<pll>ans;
        for(i=n-1;i>=0;i--){
            if(sum>=dp[i]){
                ans.push_back({i+1,arr[i].second});
                sum-=dp[i];
            }
            else{
                j=i-1;
                while(sum){
                    if(arr[j].second>arr[i].second)sum--;
                    j--;
                }
                for(ll k=0;k<=j;k++){
                    ans.push_back({k+1,arr[k].second});
                }
                ans.push_back({i+1,arr[i].second});
                for(ll k=j+1;k<i;k++){
                    ans.push_back({k+1,arr[k].second});
                }
                break;
            }
        }
        cout<<"Yes\n";
        for(auto&[x,_]:ans)cout<<x<<' ';cout<<'\n';
        for(auto&[_,x]:ans)cout<<x<<' ';
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    solve();
}