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

ll arr[21][21],n;

ll m=9999999999;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(i=0;i<(1ll<<n);i++){
        if(__builtin_popcountll(i)^n/2);
        else{
            ll k1=0,k2=0;
            for(j=0;j<n;j++){
                ll s=0;
                for(ll k=j+1;k<n;k++){
                    if(((i>>j)&1)^((i>>k)&1));
                    else s+=arr[j][k]+arr[k][j];
                }
                if((i>>j)&1){
                    k1+=s;
                }
                else{
                    k2+=s;
                }
            }
            if(m>abs(k1-k2))m=abs(k1-k2);
        }
    }
    cout<<m;
    return 0;
}
