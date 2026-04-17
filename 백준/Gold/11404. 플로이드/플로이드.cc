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
vector<vector<ll>>arr;
ll n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    arr.resize(n+1,vector<ll>(n+1,INT_MAX));
    for(i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        arr[a][b]=min(arr[a][b],c);
    }
    for(i=0;i<=n;i++){
        arr[i][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j]==INT_MAX)cout<<"0 ";
            else cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}
