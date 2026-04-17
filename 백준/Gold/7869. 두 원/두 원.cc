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
long double x1,yy1,x2,y2,r1,r2;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>x1>>yy1>>r1>>x2>>y2>>r2;
    cout<<fixed<<setprecision(3);
    long double d= (x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2);
    if(d>=(r1+r2)*(r1+r2)){
        cout<<(double)0;
    }
    else if(d<=(r1-r2)*(r1-r2)){
        cout<<min(r1,r2)*min(r1,r2)*M_PI;
    }
    else{
        long double ans=0;
        ans+=r1*r1*acos((r1*r1+d-r2*r2)/(2*r1*sqrt(d)));
        ans+=r2*r2*acos((r2*r2+d-r1*r1)/(2*r2*sqrt(d)));
        long double p=(r1+r2+sqrt(d))/2;
        ans-=2*sqrt(p*(p-r1)*(p-r2)*(p-sqrt(d)));
        cout<<ans;
    }
    return 0;
}
