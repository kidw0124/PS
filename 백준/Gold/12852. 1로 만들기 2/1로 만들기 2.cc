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
ll arr[(ll)1e6+5],brr[(ll)1e6+5],n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=2;i<=n;i++){
        arr[i]=1e6+5;
        if(!(i%3)){
            if(arr[i]>arr[i/3]+1)arr[i]=arr[i/3]+1,brr[i]=i/3;
        }
        if(!(i%2)){
            if(arr[i]>arr[i/2]+1)arr[i]=arr[i/2]+1,brr[i]=i/2;
        }
        if(arr[i]>arr[i-1]+1)arr[i]=arr[i-1]+1,brr[i]=i-1;
    }
    cout<<arr[n]<<'\n';
    while(n-1){
        cout<<n<<' ';
        n=brr[n];
    }
    cout<<1;
    return 0;
}
