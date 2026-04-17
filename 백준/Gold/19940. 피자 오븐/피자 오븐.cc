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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        cin>>n;
        vl v(5,0);
        v[0]=n/60;
        n%=60;
        if(n>35){
            v[0]++;
            n=60-n;
            v[2]=n/10;
            n%=10;
            if(n>5){
                v[2]++;
                n=10-n;
                v[3]=n;
            }
            else{
                v[4]=n;
            }
        }
        else{
            v[1]=n/10;
            n%=10;
            if(n>5){
                v[1]++;
                n=10-n;
                v[4]=n;
            }
            else{
                v[3]=n;
            }
        }
        cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<' '<<v[3]<<' '<<v[4]<<'\n';
    }
    return 0;
}
