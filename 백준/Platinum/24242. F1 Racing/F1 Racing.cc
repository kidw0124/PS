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

ll tot(ll n,ll a,ll b, ll p){
	ll q=n/a;
	ll rem=n%a;
	return q*(q+1)/2*rem*b+q*(q-1)/2*(a-rem)*b+p*(a-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i,j;
	ll n,p,r,b;
	cin>>n>>p>>r>>b;
	ll ans=r*n;
	ll s=1,e=n;
	while(s<e){
		ll m1=(s*2+e)/3,m2=(s+e*2)/3;
		ll st=tot(n,s,b,p),sm1=tot(n,m1,b,p),sm2=tot(n,m2,b,p),se=tot(n,e,b,p);
		if(sm1>sm2){
			s=m1+1;
		}
		else if(sm1<sm2){
			e=m2-1;
		}
		else{
			if(st>se)s=m1+1;
			else e=m2;
		}
	}
	//cout<<n<<' '<<s<<' ';
	cout<<ans+tot(n,s,b,p);
	return 0;
}
