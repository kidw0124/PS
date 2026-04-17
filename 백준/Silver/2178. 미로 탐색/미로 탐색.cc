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

ll ddx[4]={0,1,0,-1},ddy[4]={1,0,-1,0};

ll brr[105][105];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    vector<string> arr(n+1);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    queue<pll> st;
    st.push({0,0});
    brr[0][0]=1;
    while(!st.empty()){
        pll t=st.front();
        st.pop();
        ll x=t.first,y=t.second;
        if(x==n-1&&y==m-1){
            cout<<brr[x][y];
            return 0;
        }
        for(i=0;i<4;i++){
            ll nx=x+ddx[i],ny=y+ddy[i];
            if(ny<0||nx<0||nx>=n||ny>=m)continue;
            if(brr[nx][ny]||arr[nx][ny]=='0')continue;
            else{
                brr[nx][ny]=brr[x][y]+1;
                st.push({nx,ny});
            }
        }
    }
    return 0;
}
