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
vector<vector<ll>>grp;
vector<vector<ll>>rgrp;
vector<bool>visited;
stack<ll> st;
vector<vector<ll>>sccgroups;
vl groups;


void fillgrp(int a, char aa, int b, char bb){
    grp[a<<1|(aa=='R')].push_back(b<<1|(bb=='B'));
    grp[b<<1|(bb=='R')].push_back(a<<1|(aa=='B'));
    rgrp[a<<1|(aa=='B')].push_back(b<<1|(bb=='R'));
    rgrp[b<<1|(bb=='B')].push_back(a<<1|(aa=='R'));
}

void dfs(ll v){
    visited[v]=1;
    for(auto k:grp[v]){
        if(!visited[k])dfs(k);
    }
    st.push(v);
}

void scc(ll v){
    visited[v]=1;
    for(auto k:rgrp[v]){
        if(!visited[k])scc(k);
    }
    sccgroups.rbegin()->push_back(v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll k,n;
    cin>>k>>n;
    grp.resize(2*k+2);
    rgrp.resize(2*k+2);
    visited.resize(2*k+2);
    groups.resize(2*k+2);
    for(i=0;i<n;i++){
        ll a,b,c;
        char aa,bb,cc;
        cin>>a>>aa>>b>>bb>>c>>cc;
        fillgrp(a,aa,b,bb);
        fillgrp(c,cc,b,bb);
        fillgrp(a,aa,c,cc);
    }
    for(i=2;i<2*k+2;i++){
        if(!visited[i])dfs(i);
    }
    for(i=2;i<2*k+2;i++){
        visited[i]=0;
    }
    while(!st.empty()){
        i=st.top();
        st.pop();
        if(!visited[i]){
            sccgroups.push_back(*new vl());
            scc(i);
        }
    }

    for(auto i=sccgroups.begin();i!=sccgroups.end();i++){
        sort(i->begin(),i->end());
        for(j=0;j<i->size()-1;j++){
            groups[(*i)[j]]=i-sccgroups.begin();
            if((*i)[j]%2==0&&(*i)[j]+1==(*i)[j+1]){
                cout<<-1;
                return 0;
            }
        }
        groups[(*i)[j]]=i-sccgroups.begin();
    }
    for(i=1;i<=k;i++){
        ll a=groups[i<<1],b=groups[i<<1|1];
        if(groups[i<<1]<groups[i<<1|1])cout<<"B";
        else cout<<"R";
    }
    return 0;
}
