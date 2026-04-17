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
ll n, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>c;
    vl arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll s=0,e=1000000000;
    while(s!=e){
        ll mid=(s+e+1)/2;
        ll cn=1, prev=arr[0];
        for(i=1;i<n;i++){
            if(arr[i]-prev>=mid){
                prev=arr[i],cn++;
            }
        }
        if(cn<c)e=mid-1;
        else s=mid;
    }
    cout<<s;
    return 0;
}
