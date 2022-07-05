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
vector<pair<pll,pll>>arr;
ll n;

ll ccw (pll a, pll b, pll c){
    return ((b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second));
}
ll intersect(pair<pll,pll>x, pair<pll,pll>y){
    pll x_a=x.first,x_b=x.second,y_a=y.first,y_b=y.second;
    ll ccwx=ccw(x_a,x_b,y_a)*ccw(x_a,x_b,y_b);
    ll ccwy=ccw(y_a,y_b,x_a)*ccw(y_a,y_b,x_b);
    if(ccwx==0&&ccwy==0){
        return max(x_a,x_b)>=min(y_a,y_b)&&min(x_a,x_b)<=max(y_a,y_b);
    }
    else return ccwx<=0&&ccwy<=0;
}
vector<vector<ll>>grp;
vector<vector<ll>>rgrp;
vector<bool>visited;
stack<ll> st;
vector<vector<ll>>sccgroups;
vl groups;
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
    cin>>n;
    n*=3;
    arr.resize(2*n+2);
    grp.resize(2*n+2);
    rgrp.resize(2*n+2);
    visited.resize(2*n+2);
    groups.resize(2*n+2);
    for(i=1;i<=n;i++){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second.first>>arr[i].second.second;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(intersect(arr[i],arr[j])){
                ll a=i,b=j;
                grp[a<<1|1].push_back(b<<1);
                grp[b<<1|1].push_back(a<<1);
                rgrp[a<<1].push_back(b<<1|1);
                rgrp[b<<1].push_back(a<<1|1);
            }
        }
    }
    for(i=1;i<=n;i+=3){
        ll a=i, b=i+1, c=i+2;
        grp[a<<1].push_back(b<<1|1);
        grp[a<<1].push_back(c<<1|1);
        grp[b<<1].push_back(a<<1|1);
        grp[b<<1].push_back(c<<1|1);
        grp[c<<1].push_back(a<<1|1);
        grp[c<<1].push_back(b<<1|1);
        rgrp[a<<1|1].push_back(b<<1);
        rgrp[a<<1|1].push_back(c<<1);
        rgrp[b<<1|1].push_back(a<<1);
        rgrp[b<<1|1].push_back(c<<1);
        rgrp[c<<1|1].push_back(a<<1);
        rgrp[c<<1|1].push_back(b<<1);
    }
    for(i=2;i<(n<<1)+2;i++){
        if(!visited[i])dfs(i);
    }
    for(i=2;i<(n<<1)+2;i++){
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
    vector<ll>ans;
    for(i=1;i<=n;i++){
        if(groups[i<<1]>=groups[i<<1|1])ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(auto k:ans){
        cout<<k<<' ';
    }
    return 0;
}
