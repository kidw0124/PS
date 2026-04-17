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
vector<ll>divs;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll n,p;
	cin>>n>>p;
	vector<bool>chk(n+1);
	vector<ll>pow2(n+1,1),phi(n+1);
	iota(all(phi),0);
	phi[1]=0;
	pow2[1]=2;
	for(i=2;i<=n;i++){
		pow2[i]=pow2[i-1]<<1;
		pow2[i]%=p;
		if(phi[i]==i){
			for(j=i;j<=n;j+=i){
				phi[j]-=phi[j]/i;
			}
		}
	}
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			divs.push_back(i);
			if(i*i<n)divs.push_back(n/i);
		}
	}
	ll ans=0;
	for(auto k:divs){
		ans+=phi[k]*(pow2[n/k-1]-1);
		ans%=p;
	}
	cout<<ans*(n-2)%p;

	return 0;
}
