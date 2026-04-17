#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll t, n, m;

void dfs(ll a,vector<bool>&visit,vector<set<ll>>&vec,stack<ll>&st){
    visit[a]=1;
    for(auto k:vec[a]){
        if(!visit[k]){
            dfs(k,visit,vec,st);
        }
    }
    st.push(a);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<set<ll>>arr(n+1),brr(n+1);
        vector<bool>visit(n+1);
        for(i=0;i<m;i++){
            ll x, y;
            cin>>x>>y;
            arr[x].insert(y);
            brr[y].insert(x);
        }
        stack<ll>st;
        for(i=1;i<=n;i++){
            if(!visit[i]){
                dfs(i,visit,arr,st);
            }
        }
        fill(visit.begin(),visit.end(),0);
        ll ans=0;
        while(!st.empty()){
            ll now=st.top();
            st.pop();
            vector<ll>ppp;
            stack<ll>trs;
            if(!visit[now]){
                dfs(now,visit,brr,trs);
                set<ll> stp;
                while(!trs.empty()){
                    ppp.push_back(trs.top());
                    trs.pop();
                }
                for(auto k:ppp){
                    stp.insert(brr[k].begin(),brr[k].end());
                }
                for(auto k :ppp){
                    stp.erase(k);
                }
                if(stp.size()==0)ans++;
            }
        }
        cout<<ans<<'\n';
    }


    return 0;
}
