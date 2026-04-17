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

int n;
vi arr, brr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        int t;
        cin>>t;
        if(t>=0){
            arr.push_back(t);
        }
        else{
            brr.push_back(t);
        }
    }
    sort(arr.begin(),arr.end(),greater<int>());
    sort(brr.begin(),brr.end());
    int m=arr.size()>=2?arr[0]*arr[1]:brr[0]*brr[1];
    if(arr.size()>=3){
        m=max(m,m*arr[2]);
    }
    if(brr.size()>=2){
        if(arr.size()>=1)m=max(m,arr[0]*brr[0]*brr[1]);
        m=max(m,brr[0]*brr[1]);
    }
    cout<<m;

    return 0;
}
