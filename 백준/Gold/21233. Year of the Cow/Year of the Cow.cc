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
int n,k;
bool arr[83333334];

int ans=0;
vi brr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        if(arr[t/12])continue;
        else{
            arr[t/12]=true;
            ans++;
        }
    }
    int t=0;
    for(i=0;i<83333334;i++){
        if(!arr[i])t++;
        else{
            if(t)brr.push_back(t);
            t=0;
        }
    }
    sort(brr.begin(),brr.end());
    if(brr.size()<=k){
        cout<<ans*12;
        return 0;
    }
    for(i=0;i<brr.size()+1-k;i++){
        ans+=brr[i];
    }
    cout<<ans*12;
    return 0;
}
