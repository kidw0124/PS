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
ll n, m,v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m>>v;
    vector<set<ll>>arr(n+1);
    vector<bool>visited(n+1);
    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    stack<ll>st;
    st.push(v);
    while(!st.empty()){
        ll t=st.top();
        st.pop();
        if(visited[t])continue;
        visited[t]=1;
        cout<<t<<' ';
        for(auto k=arr[t].rbegin();k!=arr[t].rend();k++){
            if(!visited[*k])st.push(*k);
        }
    }
    cout<<'\n';
    queue<ll>que;
    que.push(v);
    while(!que.empty()){
        ll t=que.front();
        que.pop();
        if(!visited[t])continue;
        visited[t]=0;
        cout<<t<<' ';
        for(auto k=arr[t].begin();k!=arr[t].end();k++){
            if(visited[*k])que.push(*k);
        }

    }
    return 0;
}
