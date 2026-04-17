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
ll m,n;
set<vector<ll>>ans;

void print(int a, vector<ll>&b,vector<ll>&arr,int c){
    if(a==m){
        for(auto k:b){
            cout<<k<<' ';
        }
        cout<<'\n';
    }
    else{
        for(ll i=c;i<n;i++){
            b[a]=arr[i];
            print(a+1,b,arr,i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>m;
    vector<ll>arr(n),brr(m);
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    print(0,brr,arr,0);
    return 0;
}
