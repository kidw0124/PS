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
ll maxlens[10010];

ll func(ll x, ll y){
    if(x==0&&y==0)return 1;
    ll i=max(abs(x),abs(y));
    ll nowx=i, nowy=i;
    ll nowv=(2*i+1)*(2*i+1);
    ll j;
    for(j=0;j<2*i;j++){
        if(nowx==x&&nowy==y){
            return nowv;
        }
        else nowv--,nowy--;
    }
    for(j=0;j<2*i;j++){
        if(nowx==x&&nowy==y){
            return nowv;
        }
        else nowv--,nowx--;
    }
    for(j=0;j<2*i;j++){
        if(nowx==x&&nowy==y){
            return nowv;
        }
        else nowv--,nowy++;
    }
    for(j=0;j<2*i;j++){
        if(nowx==x&&nowy==y){
            return nowv;
        }
        else nowv--,nowx++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,xxxx=0;
    ll nowx=5000,nowy=5000;
    ll r1,r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    for(i=c1;i<=c2;i++){
        for(j=r1;j<=r2;j++){
            maxlens[i+5000]=max(maxlens[i+5000],(ll)to_string(func(j,i)).size());
        }
        xxxx=max(xxxx,maxlens[i+5000]);
    }
    for(i=r1;i<=r2;i++){
        for(j=c1;j<=c2;j++){
            if(j!=c1)cout<<' ';
            for(ll k=0;k<xxxx-to_string(func(i,j)).size();k++){
                cout<<' ';
            }
            cout<<func(i,j);
        }
        cout<<'\n';
    }
    return 0;
}
