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
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,j;
	ll t,n;
	for(;;){
		ll x,y;
		cin>>x>>y;
		pll now={x,y};
		n=3;
		vector<pll>arr(n+1);
		arr[0]=now;
		ll a,e=0,s=0;
		for(i=0;i<n-1;i++){
			ll dx,dy;
			cin>>dx>>dy;
			arr[i+1]={dx,dy};
			e+=gcd(abs(dx-arr[i].first),abs(dy-arr[i].second));
		}
		e+=gcd(abs(arr[0].first-arr[i].first),abs(arr[0].second-arr[i].second));
		arr[3]=now;
		for(i=0;i<n;i++){
			s+=arr[i].first*arr[i+1].second-arr[i].second*arr[i+1].first;
		}
		s=abs(s);
		if(s==0)break;
		a=s+2-e;
		cout<<a/2<<"\n";
	}

	return 0;
}
