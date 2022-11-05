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
ll k=0,n;
long double a,b,ans,dx;
long double origin[11],integrate[12];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>k;
    for(i=0;i<=k;i++){
        cin>>origin[k-i];
        integrate[k-i+1]=origin[k-i]/(long double)(k-i+1);
    }
    cin>>a>>b>>n;
    dx=(b-a)/n;
    for(i=1;i<=k+1;i++){
        ans+=integrate[i]*(pow(b,i)-pow(a,i));
    }
    long double st=0,en=10,ans2=0,mid;
    do{
        ans2=0;
        mid=(st+en)/2;
        for(i=0;i<n;i++){
            for(j=0;j<=k;j++){
                ans2+=origin[j]*(pow(a+i*dx+mid,j))*dx;
            }
        }
        if(abs(ans2-ans)<1e-5)st=en=mid;
        else if(ans2>ans)en=mid;
        else st=mid;
    }while(st<en);
    cout<<fixed<<st;
    return 0;
}
