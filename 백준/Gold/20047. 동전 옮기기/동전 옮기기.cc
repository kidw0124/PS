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
ll n,x,y;
string f,k;
string oi;

bool ispos(int idx,int inx){
    if(idx==n-2&&inx==2){
        return 1;
    }
    if(idx<n-2&&f[idx]==k[idx+inx]){
        if(ispos(idx+1,inx))return 1;
    }
    if(inx<2&&oi[inx]==k[idx+inx]){
        if(ispos(idx,inx+1))return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    cin>>f>>k>>x>>y;
    oi="";
    oi.push_back(f[x]);
    oi.push_back(f[y]);
    f.erase(f.begin()+x);
    f.erase(f.begin()+y-1);
    cout<<(ispos(0,0)?"YES":"NO");
    return 0;
}
