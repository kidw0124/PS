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
long double st,en,mid;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll a,b,c;
    cin>>a>>b>>c;
    st=(c-b)/(long double)a,en=(c+b)/(long double)a;
    while(en-st>(long double)0.0000000001){
        mid=(st+en)/2;
        long double lhs=a*mid+b*(long double)sin(mid);
        if(lhs<c){
            st=mid;
        }
        else if(lhs==c)break;
        else{
            en=mid;
        }
    }
    cout<<fixed<<setprecision(25)<<mid;
    return 0;
}
