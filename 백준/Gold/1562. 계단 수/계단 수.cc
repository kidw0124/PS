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
ll arr[102][10][1024];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k;
    ll n;
    cin>>n;
    for(i=1;i<=9;i++){
        arr[1][i][1<<i]=1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=8;j++){
            for(k=0;k<1024;k++){
                arr[i][j][k|(1<<j)]+=(arr[i-1][j+1][k]+arr[i-1][j-1][k]);
                arr[i][j][k|(1<<j)]%=(ll)(1e9);
            }
        }
        for(k=0;k<1024;k++){
            arr[i][0][k|1]+=(arr[i-1][1][k]);
            arr[i][0][k|1]%=(ll)(1e9);
        }
        for(k=0;k<1024;k++){
            arr[i][9][k|(1<<9)]+=(arr[i-1][8][k]);
            arr[i][j][k|(1<<9)]%=(ll)(1e9);
        }
    }
    ll maxx=0;
    for(i=0;i<=9;i++){
        maxx+=arr[n][i][1023];
    }
    cout<<maxx%(ll)(1e9);
    return 0;
}
