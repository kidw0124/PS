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
ll v,e;
vector<vector<ll>>grp;
vector<vector<ll>>rgrp;
vector<bool>visited;
stack<ll> st;
vector<vector<ll>>sccgroups;
vector<pll> vct;
void dfs(ll points){
    visited[points]=1;
    for(auto k : rgrp[points]){
        if(visited[k])continue;
        else dfs(k);
    }
    st.push(points);
}
void scc(ll points){
    visited[points]=1;
    for(auto k : grp[points]){
        if(visited[k])continue;
        else scc(k);
    }
    sccgroups.rbegin()->push_back(points);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>v>>e;
    grp.resize(v+1);
    rgrp.resize(v+1);
    visited.resize(v+1,false);
    for(i=1;i<=v;i++){
        visited[i]=0;
    }
    for(i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        rgrp[a].pb(b);
        grp[b].pb(a);
    }
    for(i=1;i<=v;i++){
        if(visited[i])continue;
        else dfs(i);
    }
    for(i=1;i<=v;i++){
        visited[i]=0;
    }
    while(!st.empty()){
        i= st.top();
        st.pop();
        if(visited[i])continue;
        else {
            sccgroups.push_back(*new vl());
            scc(i);
        }
    }
    for(i=0;i<sccgroups.size();i++){
        sort(sccgroups[i].begin(),sccgroups[i].end());
        vct.push_back({sccgroups[i][0],i});
    }
    sort(vct.begin(),vct.end());
    cout<<sccgroups.size()<<'\n';
    for(auto x:vct){
        for(auto y:sccgroups[x.second]){
            cout<<y<<' ';
        }
        cout<<"-1\n";
    }

    return 0;
}
