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
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    ll i,j;
    cin>>n;
    vector<vector<ll>>arr(n+1,vector<ll>(n+1,1000000000000000ll));
    vl brr(n+1);
    cin>>brr[0];
    for(i=0;i<n-1;i++)cin>>brr[i+1]>>j;
    cin>>brr[n];
    for(i=0;i<n;i++){
        arr[i][i]=0;
    }
    arr[i][i]=0;
    for(i=1;i<n;i++){
        for(j=1;j+i<=n;j++){
            for(ll k=j;k<j+i;k++){
                arr[j][i+j]=min(arr[j][i+j],arr[j][k]+arr[k+1][i+j]+brr[j-1]*brr[k]*brr[i+j]);
            }
        }
    }
    cout<<arr[1][n]<<'\n';

    return 0;
}
