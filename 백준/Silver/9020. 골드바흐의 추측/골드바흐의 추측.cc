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
bool ppp[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,n,t;
    cin>>t;
    for(i=2;i+i<=10000;i++){
        for(j=2;i*j<=10000;j++)ppp[i*j]=1;
    }
    while(t--){
        cin>>n;
        for(i=n/2;i>=2;i--){
            if(ppp[i]||ppp[n-i])continue;
            else {
                cout<<i<<' '<<n-i<<'\n';
                break;
            }
        }
    }

    return 0;
}
