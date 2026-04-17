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
struct pppp{
    pii a;
    int c=1;
};

bool cmp2(pppp x,pppp y){
    return x.a.first>y.a.first&&x.a.second>y.a.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n;
    cin>>n;
    vector<pppp>ppppp(n);
    for(i=0;i<n;i++)cin>>ppppp[i].a.first>>ppppp[i].a.second;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(cmp2(ppppp[j],ppppp[i]))ppppp[i].c++;
    for(auto i:ppppp){
        cout<<i.c<<' ';
    }
    return 0;
}
