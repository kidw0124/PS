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
vector<vector<pll>>arr;
vector<ll>dist;
vector<ll>prevn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1);
    dist.resize(n+1,INT_MAX);
    prevn.resize(n+1);
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back({b,c});
    }
    ll s,e;
    cin>>s>>e;
    dist[s]=0;
    prevn[s]=s;
    priority_queue<pll>pq;
    pq.push({0,s});
    while(!pq.empty()){
        ll nowv=pq.top().second,nowc=-pq.top().first;
        pq.pop();
        if(nowc!=dist[nowv])continue;
        if(nowv==e)break;
        for(auto k:arr[nowv]){
            if(dist[k.first]>dist[nowv]+k.second){
                dist[k.first]=dist[nowv]+k.second;
                prevn[k.first]=nowv;
                pq.push({-dist[k.first],k.first});
            }
        }
    }
    cout<<dist[e]<<'\n';
    stack<ll>st;
    while(e!=prevn[e]){
        st.push(e);
        e=prevn[e];
    }
    cout<<st.size()+1<<'\n'<<s<<' ';
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    return 0;
}
