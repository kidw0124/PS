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
ll t,n;
pll st, en;

ll dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};

ll dfs(pll a, pll b){
    queue<pair<pll,ll>>que;
    que.push({a,0});
    vector<vector<bool>>visit(n,vector<bool>(n));
    visit[a.first][a.second]=1;
    while(!que.empty()){
        ll nx=que.front().first.first,ny=que.front().first.second,c=que.front().second;
        if(make_pair(nx,ny)==b){
            return c;
        }
        que.pop();
        for(int i=0;i<8;i++){
            ll nnx=nx+dx[i],nny=ny+dy[i];
            if(nnx<0||nny<0||nnx>=n||nny>=n||visit[nnx][nny]){
                continue;
            }
            visit[nnx][nny]=1;
            que.push({{nnx,nny},c+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>st.first>>st.second;
        cin>>en.first>>en.second;
        cout<<dfs(st,en)<<'\n';
    }

    return 0;
}
