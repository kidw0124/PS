#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int>factor(10'000);

void preprocess(){
    int i,j;
    for(i=2;i<10'000;i++){
        if(!factor[i]){
            for(j=i*2;j<10'000;j+=i){
                factor[j]=i;
            }
        }
    }
}

void solve(){
    ll i,j;
    ll n,ans=0;
    cin>>n;
    vector<pll>arr(n);
    for(auto&[a,_]:arr){
        cin>>a;
    }
    vector<vector<ll>>grp(1e6+1);
    for(auto&[a,b]:arr){
        cin>>b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    vector<ll>vis(1e6+1);
    for(i=1;i<=1e6;i++){
        if(!vis[i]){
            queue<ll>q;
            q.push(i);
            vis[i]=1;
            ll tmp=0,m=0;
            while(q.size()){
                ll cur=q.front();
                m++;
                q.pop();
                for(auto nxt:grp[cur]){
                    tmp++;
                    if(!vis[nxt]){
                        vis[nxt]=1;
                        q.push(nxt);
                    }
                }
            }
            if(tmp==2*(m-1))ans+=m-1;
            else ans+=m;
        }
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
}