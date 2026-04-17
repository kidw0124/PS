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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,x;
    cin>>n>>m;
    vector<ll>visit(200001,-1);
    queue<ll> que;
    que.push(n);
    visit[n]=n;
    while(!que.empty()){
        ll now=x=que.front();
        que.pop();
        if(now==m)break;
        if(x-1>=0&&visit[x-1]==-1){
            visit[x-1]=now;
            que.push(x-1);
        }
        if(x+1<=200000&&visit[x+1]==-1){
            visit[x+1]=now;
            que.push(x+1);
        }
        if(2*x<=200000&&visit[2*x]==-1){
            visit[2*x]=now;
            que.push(2*x);
        }
    }
    stack<ll>st;
    ll k=m;
    while(k!=visit[k]){
        st.push(k=visit[k]);
    }
    cout<<st.size()<<'\n';
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<m;
    return 0;
}
