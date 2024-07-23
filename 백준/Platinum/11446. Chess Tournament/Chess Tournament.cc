#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e8;

void solve(){
    int i,j,k;
    ll n,m;
    cin>>n>>m;
    vector<ll>dp(n<<1);
    vector<set<ll>>island(n<<1|1);
    vector<bool>vis(n<<1);
    vector<set<ll>>grp(n<<1);
    for(i=0;i<(n<<1);i++){
        for(j=0;j<(n<<1);j++){
            grp[i].insert(j);
        }
        grp[i].erase(i);
    }
    for(i=0;i<m;++i){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        grp[a].erase(b);
        grp[b].erase(a);
    }
    for(i=0;i<(n<<1);i++){
        if(vis[i])continue;
        vis[i]=1;
        queue<ll>que({i});
        set<ll>tmp;
        while(!que.empty()){
            ll cur=que.front();
            que.pop();
            tmp.insert(cur);
            for(auto nxt:grp[cur]){
                if(vis[nxt])continue;
                vis[nxt]=1;
                que.push(nxt);
            }
        }
        if(i){
            for(j=n;j>=tmp.size();j--){
                dp[j]+=dp[j-tmp.size()];
                dp[j]%=MOD;
                if(dp[j-tmp.size()]&&island[j-tmp.size()].size()){
                    island[j]=island[j-tmp.size()];
                    island[j].insert(tmp.begin(),tmp.end());
                }
            }
        }
        else{
            dp[tmp.size()]=1;
            island[tmp.size()]=tmp;
        }
    }
    cout<<dp[n]<<'\n';
    for(auto it:island[n]){
        cout<<it+1<<' ';
    }
    cout<<'\n';

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}