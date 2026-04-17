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
    vector<int>visit(150001);
    deque<int> que;
    visit[n]=1;
    que.push_front(n);
    while(1){
        int now=que.front();
        que.pop_front();
        if(now==m){
            cout<<visit[now]-1;
            return 0;
        }
        int next=now-1;
        if(next>=0&&(!visit[next]||visit[next]>visit[now])){
            visit[next]=visit[now]+1;
            que.push_back(next);
        }
        next=now+1;
        if(next<=131072&&(!visit[next]||visit[next]>visit[now])){
            visit[next]=visit[now]+1;
            que.push_back(next);
        }
        next=now*2;
        if(next<=131072&&(!visit[next]||visit[next]>visit[now])){
            visit[next]=visit[now];
            que.push_front(next);
        }
    }


    return 0;
}
