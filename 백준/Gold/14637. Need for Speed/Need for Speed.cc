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

const ll MAXN=1000+5;
ll n,t;
double mini=-1e9,maxi=1e9;
vector<double>d(MAXN),s(MAXN);

int main(){
    cin>>n>>t;
    for(ll i=0;i<n;i++){
        cin>>d[i]>>s[i];
        mini=max(mini,-s[i]);
    }
    while(maxi-mini>1e-8){
        double c=(maxi+mini)/2, te=0;
        for(ll i=0;i<n;i++){
            te+=d[i]/(s[i]+c);
        }
        if(te>t)mini=c;
        else maxi=c;
    }
    cout<<fixed<<setprecision(7)<<maxi;
}
