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
ll n,m;
char str[3]="BW";
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    vector<string>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    int mmm=64;
    for(i=0;i+7<n;i++){
        for(j=0;j+7<m;j++){
            int cnt=0;
            for(ll k=i;k<i+8;k++){
                for(ll l=j;l<j+8;l++){
                    if(str[(k+l)%2]==arr[k][l])cnt++;
                }
            }
            mmm=min(mmm,cnt);
            mmm=min(mmm,64-cnt);
        }
    }
    cout<<mmm;
    return 0;
}
