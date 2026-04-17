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
ll n,k;
ll arr[104][100005];
pll brr[104];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>brr[i].first>>brr[i].second;
    for(i=0;i<n;i++){
        for(j=1;j<=k;j++){
            if(i==0){
                arr[i][j]=(j>=brr[i].first?brr[i].second:0);
            }
            else if(brr[i].first<=j){
                arr[i][j]=max(arr[i-1][j],brr[i].second+arr[i-1][j-brr[i].first]);
            }
            else arr[i][j]=arr[i-1][j];
        }
    }
    cout<<*max_element(arr[n-1]+1,arr[n-1]+k+1);
    return 0;
}
