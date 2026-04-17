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
ll INF=INT_MAX;
vector<vector<pair<ll,char>>>arr(10001);
ll L(ll a){
    string s=to_string(a);
    while(s.size()<4)s='0'+s;
    s=s.substr(1)+s[0];
    return stoll(s);
}
ll R(ll a){
    string s=to_string(a);
    while(s.size()<4)s='0'+s;
    s=s[3]+s.substr(0,3);
    return stoll(s);
}


void dfs(ll s, ll e){
    vector<ll>dist(10001,INF);
    vector<pair<ll,char>>pre(10001);
    dist[s]=0;
    pre[s]={s,'\0'};
    queue<ll>pq;
    pq.push(s);
    while(!pq.empty()){
        ll nowv=pq.front();
        pq.pop();
        for(auto k:arr[nowv]){
            if(dist[k.first]==INF){
                dist[k.first]=dist[nowv]+1;
                pq.push(k.first);
                pre[k.first]={nowv,k.second};
                if(k.first==e){
                    stack<char>st;
                    while(e!=s){
                        st.push(pre[e].second);
                        e=pre[e].first;
                    }
                    while(!st.empty()){
                        cout<<st.top();
                        st.pop();
                    }
                    cout<<'\n';
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    for(i=0;i<10000;i++){
        arr[i].push_back({i*2%10000,'D'});
        arr[i].push_back({(i+9999)%10000,'S'});
        arr[i].push_back({L(i),'L'});
        arr[i].push_back({R(i),'R'});
    }
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        dfs(a,b);
    }
    return 0;
}
