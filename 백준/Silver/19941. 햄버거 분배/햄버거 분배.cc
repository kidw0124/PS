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
ll n,k,cnt;
bool visit[20000+5];
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k>>s;
    for(i=0;i<n;i++){
        if(s[i]=='P')visit[i]=1;
    }
    for(i=0;i<n;i++){
        if(s[i]=='P'){
            for(j=max(0ll,i-k);j<=min(i+k,n-1);j++){
                if(visit[j]==0){
                    visit[j]=1;
                    cnt++;
                    goto abc;
                }
            }
        }
        abc:;
    }
    cout<<cnt;
    return 0;
}
