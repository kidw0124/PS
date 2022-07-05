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
ll n,m;
vector<vector<ll>>grp;
vector<vector<ll>>rgrp;
vector<bool>visited;
stack<ll> st;
vector<vector<ll>>sccgroups;

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
    cin>>n>>m;
    grp.resize(2*n+2);
    rgrp.resize(2*n+2);
    visited.resize(2*n+2);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        grp[abs(a)*2+(a>0)].push_back(abs(b)*2+(b<0));
        grp[abs(b)*2+(b>0)].push_back(abs(a)*2+(a<0));
        rgrp[abs(a)*2+(a<0)].push_back(abs(b)*2+(b>0));
        rgrp[abs(b)*2+(b<0)].push_back(abs(a)*2+(a>0));
    }
    for(i=2;i<2*n+2;i++){
        if(!visited[i])dfs(i);
    }
    for(i=2;i<2*n+2;i++){
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
            if((*i)[j]%2==0&&(*i)[j]+1==(*i)[j+1]){
                cout<<0;
                return 0;
            }
        }
    }
    cout<<"1\n";
    return 0;
}
