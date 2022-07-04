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
ll n,m,s,p;
vector<ll>par;
vector<vector<ll>>arr,brr;
vector<set<ll>>crr;
vector<ll>atm;
vector<bool>vvist,vvvisit;
vector<ll>rest;
vector<vector<ll>>scc;
vector<ll>money,pprev;
stack<ll> st;
vector<ll>id;

void dfs(ll x,vector<vector<ll>>&arrr){
    for(auto k:arrr[x]){
        if(vvvisit[k]==0){
            vvvisit[k]=1;
            dfs(k,arrr);
        }
    }
    st.push(x);
}

void dfs2(ll x, vector<vector<ll>>&arrr){
    vector<ll> vt;
    stack<ll> sst;
    sst.push(x);
    while(!sst.empty()){
        ll now=sst.top();
        sst.pop();
        id[now]=scc.size();
        vt.push_back(now);
        for(auto k:arrr[now]){
            if(vvist[k]==0&&vvvisit[k]){
                vvist[k]=1;
                sst.push(k);
            }
        }
    }
    scc.push_back(vt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1),atm.resize(n+1),brr.resize(n+1),vvist.resize(n+1),vvvisit.resize(n+1),id.resize(n+1,-1);
    for(i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        arr[x].push_back(y);
        brr[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        cin>>atm[i];
    }
    cin>>s>>p;
    for(i=0;i<p;i++){
        ll x;
        cin>>x;
        rest.push_back(x);
    }
    vvvisit[s]=1;
    dfs(s,arr);
    ll ans=0;
    //fill(vvist.begin(),vvist.end(),0);
    while(!st.empty()){
        ll now=st.top();
        //cout<<now<<'\n';
        st.pop();
        if(vvist[now])continue;
        else{
            vvist[now]=1;
            dfs2(now,brr);
        }
    }
    for(i=0;i<scc.size();i++){
        //for(auto k:scc[i])cout<<k<<' ';
        //cout<<'\n';

    }
    crr.resize(scc.size());
    par.resize(scc.size());
    money.resize(scc.size());
    pprev.resize(scc.size(),0);
    ll star=0;
    for(i=0;i<scc.size();i++){
        for(auto kk:scc[i]){
            if(kk==s)star=i;
            money[i]+=atm[kk];
            for(auto k:arr[kk]){
                if(id[k]==id[kk])continue;
                else{
                    if(crr[id[kk]].find(id[k])!=crr[id[kk]].end())continue;
                    crr[id[kk]].insert(id[k]);
                    par[id[k]]++;
                }
            }
        }
    }
    queue<ll>que;
    for(i=0;i<scc.size();i++){
        if(par[i]==0){
            que.push(i);
            pprev[i]=0;
        }
    }
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        if(now==id[s])continue;
        for(auto k:crr[now]){
            if(par[k]<0)continue;
            par[k]--;
            if(par[k]==0){
                que.push(k);
            }
        }
    }
    que.push(id[s]);
    while(!que.empty()){
        ll now=que.front();
        que.pop();
        for(auto k:crr[now]){
            if(par[k]<0)continue;
            pprev[k]=max(pprev[k],pprev[now]+money[now]);
            par[k]--;
            if(par[k]==0){
                que.push(k);
            }
        }
    }
    for(auto k:rest){
        if(id[k]!=-1)ans=max(ans,money[id[k]]+pprev[id[k]]);
    }
    cout<<ans;
    return 0;
}
