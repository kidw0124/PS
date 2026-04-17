#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pld = pair<ld,ld>;
#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx,avx2,fma")
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif

#define debug if constexpr(ddebug) cout<<"[DEBUG] "

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

void preprocess(){
    ll i,j;
}

void solve(ll testcase){
    ll n,i,j,k;
    char m;
    cin>>n>>m;
    vector<string>arr(n);
    vector<pll>mal;
    ll x,y;
    for(i=0;i<n;i++){
        cin>>arr[i];
        for(j=0;j<n;j++){
            if(arr[i][j]==m){
                mal.push_back({i+1,j+1});
            }
        }
    }
    k=mal.size();
    vector<ll>vis(k);
    vector<vector<ll>>grp(k);
    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            bool b=0;
            switch (m) {
                case 'R':
                    b=(mal[i].first==mal[j].first
                            ||mal[i].second==mal[j].second);
                    break;
                case 'Q':
                    b=(mal[i].first==mal[j].first
                       ||mal[i].second==mal[j].second
                       ||mal[i].first+mal[i].second==mal[j].first+mal[j].second
                       ||mal[i].first-mal[i].second==mal[j].first-mal[j].second);
                    break;
                case 'B':
                    b=(mal[i].first+mal[i].second==mal[j].first+mal[j].second
                       ||mal[i].first-mal[i].second==mal[j].first-mal[j].second);
                    break;
                case 'N':
                    b=(abs(mal[i].first-mal[j].first)
                            +abs(mal[i].second-mal[j].second)==3
                        &&mal[i].first!=mal[j].first
                        &&mal[i].second!=mal[j].second);
                    break;
                case 'K':
                    b=(abs(mal[i].first-mal[j].first)<=1 &&
                            abs(mal[i].second-mal[j].second)<=1);
                    break;
            }
            if(b){
                grp[i].push_back(j);
                grp[j].push_back(i);
            }
        }
    }
    queue<ll>que;
    que.push(0);
    vis[0]=1;
    stack<pair<pll,pll>>stk;
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto p:grp[now]){
            if(!vis[p]){
                vis[p]=1;
                stk.push({mal[p],mal[now]});
                que.push(p);
            }
        }
    }
    if(stk.size()==k-1){
        cout<<"YES\n";
        while(!stk.empty()){
            auto [a,b]=stk.top();
            cout<<a.first<<' '<<a.second<<' '<<b.first<<' '<<b.second<<'\n';
            stk.pop();
        }
    }
    else cout<<"NO\n";

}

int main(){
    setup();
    preprocess();
    ll t=1;
//    cin>>t;
    for(ll tc=0;tc<t;tc++){
        solve(tc+1);
    }
}