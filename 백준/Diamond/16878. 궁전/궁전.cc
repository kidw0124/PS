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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll t=1;
	vector<ll>arr({1,1,0,0});
	arr.resize(10'000'005);
	ll mod=1'000'000'007;
	for(i=4;i<10'000'005;i++){
		arr[i]=(i*((arr[i-1]-arr[i-2]-arr[i-3]+arr[i-4])%mod+mod)%mod+arr[i-1]+2*arr[i-2]+5*arr[i-3]-3*arr[i-4])%mod+mod;
		arr[i]%=mod;
	}
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<arr[n]<<'\n';
	}

	return 0;
}
