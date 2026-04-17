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
	ll n,m,p;
	cin>>n>>m>>p;
	vector<vector<ll>>comb(p+1,vector<ll>(p+1));
	for(i=0;i<p;i++){
		comb[i][0]=comb[i][i]=1;
		for(j=1;j<i;j++){
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			comb[i][j]%=p;
		}
	}
	ll ans=1;
	while(m){
		ans*=comb[n%p][m%p];
		ans%=p;
		n/=p,m/=p;
	}
	cout<<ans;
	return 0;
}
